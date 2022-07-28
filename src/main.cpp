// 'X' 'S' 0xFF id 0000 data 'Y'
// 'X' 'D' 0xFFF id 000 data 'Y'
// 'p' 0/1 state 255 pin

// https://wokwi.com/projects/337267688980087380

// main arduino soll ALLE dcc-adressen mit werten an serial weitergeben
// addressierung von rechts nach links
// wenn die telegramm-werte zu dumm sind:
// uint8_t tele_dcc_matrix[] = {0, 3, 1};
// sodass set() die neuen sinnvollen werte kriegt
// debug info serial.print (addressbereiche, signal-#, info-pdf)
// neue signale mit ws2811 auf pcb? -> signals[] = {new Vr(), new Hp(),new Hp()} ws- & dcc- (addr-offset) addressierung nach index
// https://lcsc.com/product-detail/Light-Emitting-Diodes-LED_Worldsemi-WS2812B-Mini_C527089.html
// -> dimmbar (glühbirnen-nachglühen simulieren), alle farben & kombinationen
// -> nur ein datenkabel & steuerarduino (auf strom achten)
// -> einfachere ansteuerung
// -> passend auf 3d-signalschirm
// -> ohne signalschirm nutzbar mit schwarzem pcb und komponenten auf rückseite
// -> denk an die schraubenlöcher! (genug abstand zum aufbohren)

// WICHTIG: lass mal den ganzen arduinos namen geben (albert, berta, cedric, dominik, eugen...)

#include <Arduino.h>
#include "signal.h"
#include "signals/hp.h"
#include "signals/vr.h"

#include "devices/nano1.h"

uint8_t signals_len = sizeof(signals) / sizeof(Signal *);

void setup()
{
  Serial.begin(9600);
  Serial.setTimeout(5000);

  setupSignals();
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

uint8_t getTeleAddress(uint8_t *buffer)
{
  return hexToDec(buffer[1]) * 16 +
         hexToDec(buffer[2]);
}

uint16_t getTeleAddressExt(uint8_t *buffer)
{
  return hexToDec(buffer[1]) * 256 +
         hexToDec(buffer[2]) * 16 +
         hexToDec(buffer[3]);
}

uint16_t getTeleData(uint8_t *buffer)
{
  return hexToDec(buffer[4]) * 256 +
         hexToDec(buffer[5]) * 16 +
         hexToDec(buffer[6]);
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

Signal *findSignalDCC(uint8_t *buffer)
{
  uint16_t address = getTeleAddressExt(buffer);
  for (uint8_t i = 0; i < signals_len; i++)
    if (signals[i]->dcc_address == address)
      return signals[i];
  return nullptr;
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
      char tele_type = tele_buffer[0];
      uint16_t data = getTeleData(tele_buffer);

      Signal *signal = nullptr;
      if (tele_type == 'D')
        signal = findSignalDCC(tele_buffer);
      else
        signal = findSignalTele(tele_buffer);

      if (signal != nullptr)
      {
        if (data == 0xF00) // Signalstatus
          Serial.write(signal->last_value);
        else if (data == 0xF01) // Signal-Telegrammtyp
          Serial.write(signal->teleType());
        else // Standard: Signal setzen
          signal->set(data);
      }
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
