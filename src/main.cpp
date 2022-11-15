// Telegram 'X' 'S' 00 [kanal] 0xFFFF [wert] 'Y'
// DCC      'X' 'D' 0xFFFF [id] 0xFF [wert] 'Y'
// Pin      'p' 0/1 [wert] 00 [pin]

// https://wokwi.com/projects/337267688980087380

// DCC -> Serial Addr
//  0...2000 Signal Addresse
//  2000...4000 Weichen oder so

// neue signale mit ws2811 auf pcb? -> signals[] = {new Vr(), new Hp(),new Hp()} ws- & dcc- (addr-offset) addressierung nach index
// https://lcsc.com/product-detail/Light-Emitting-Diodes-LED_Worldsemi-WS2812B-Mini_C527089.html
// -> dimmbar (glühbirnen-nachglühen simulieren), alle farben & kombinationen
// -> nur ein datenkabel & steuerarduino (auf strom achten)
// -> einfachere ansteuerung
// -> passend auf 3d-signalschirm
// -> ohne signalschirm nutzbar mit schwarzem pcb und komponenten auf rückseite
// -> denk an die schraubenlöcher! (genug abstand zum aufbohren)

#include <Arduino.h>
#include "signal.h"
#include "signals/hp.h"
#include "signals/vr.h"

#include "devices/nano9.h"

uint8_t signals_len = sizeof(signals) / sizeof(Signal *);

void setup()
{
  Serial.begin(9600);
  Serial.setTimeout(5000);

  setupSignals();

  Serial.print(signals_len);
  Serial.println(" signals:");
  for (uint8_t i = 0; i < signals_len; i++)
  {
    Serial.print("Signal (");
    Serial.print(signals[i]->signalType());
    Serial.print("):\tDCC ");
    Serial.print(signals[i]->dcc_address);
    Serial.print(" / Kanal ");
    Serial.println(signals[i]->channel);
  }
  for (uint8_t i = 0; i < signals_len; i++)
    signals[i]->setup();

  delay(100);
}

uint8_t hexToDec(uint8_t c)
{
  if (c >= 'A')
    return 10 + c - 'A';
  else
    return c - '0';
}

uint16_t getTeleAddress(uint8_t *buffer)
{
  if (buffer[0] == 'D')
  {
    return hexToDec(buffer[1]) * 4096 +
           hexToDec(buffer[2]) * 256 +
           hexToDec(buffer[3]) * 16 +
           hexToDec(buffer[4]);
  }
  else
  {
    return (buffer[1] - '0') * 10 +
           (buffer[2] - '0');
  }
}

uint16_t getTeleData(uint8_t *buffer)
{
  if (buffer[0] == 'D')
  {
    return hexToDec(buffer[5]) * 16 +
           hexToDec(buffer[6]);
  }
  else
  {
    return hexToDec(buffer[3]) * 4096 +
           hexToDec(buffer[4]) * 256 +
           hexToDec(buffer[5]) * 16 +
           hexToDec(buffer[6]);
  }
}

Signal *findSignalTele(uint8_t *buffer)
{
  uint16_t address = getTeleAddress(buffer);
  for (uint8_t i = 0; i < signals_len; i++)
    if (signals[i]->channel == address &&
        signals[i]->teleType() == buffer[0])
      return signals[i];
  return nullptr;
}

void setSignal(uint8_t *buffer)
{
  uint16_t address = getTeleAddress(buffer);
  uint16_t value = getTeleData(buffer);

  if (buffer[0] == 'D')
  {
    for (uint8_t i = 0; i < signals_len; i++)
    {
      if (signals[i]->dcc_address == address)
        signals[i]->set(value);
    }
  }
  else
  {
    for (uint8_t i = 0; i < signals_len; i++)
    {
      if (signals[i]->channel == address &&
          signals[i]->teleType() == buffer[0])
        signals[i]->set(signals[i]->fromTeleValue(value));
    }
  }
}

void loop()
{
  for (uint8_t i = 0; i < signals_len; i++)
    signals[i]->loop();

  while (Serial.available())
  {
    char c = Serial.read();
    if (c == 'X') // Telegramm
    {
      uint8_t tele_buffer[8];
      Serial.readBytes(tele_buffer, 8);
      setSignal(tele_buffer);
    }
    else if (c == 'p') // Pin control
    {
      while (!Serial.available())
        ;
      bool state = Serial.read() == '1';

      while (!Serial.available())
        ;
      uint8_t pin = Serial.readStringUntil('\n').toInt();
      pinMode(pin, OUTPUT);
      digitalWrite(pin, state);
    }
  }
}
