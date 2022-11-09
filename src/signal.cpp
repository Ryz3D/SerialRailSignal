#include "signal.h"

Signal::Signal(uint8_t channel, uint16_t dcc_address)
{
    this->channel = channel;
    this->dcc_address = dcc_address;
}

void Signal::setup()
{
    internalSetup();
}

void Signal::set(uint8_t value, bool tele)
{
    if (tele)
        value = transformSignal(value);

    last_value = value;
    blink_state = 1;
    last_blink = millis();
    internalSet(OFF);
    internalSet(value);

#if SIGNAL_DEBUG == 1
    Serial.print("DEBUG: ");
    Serial.print(dcc_address);
    Serial.print(" set to ");
    Serial.print(value);
    Serial.println();
#endif
}

void Signal::loop()
{
    if (millis() > last_blink + blink_delay)
    {
        blink_state = !blink_state;
        last_blink = millis();
    }
    internalLoop();
}

char Signal::teleType()
{
    return 'S';
}

const char *Signal::signalType()
{
    return "?";
}

void Signal::internalSetup() {}

void Signal::internalSet(uint8_t signal)
{
    Serial.println("Signal:::set not implemented!");
}

uint8_t Signal::transformSignal(uint8_t signal)
{
    return signal;
}

void Signal::internalLoop() {}

void Signal::writePin(int8_t pin, bool state)
{
    if (pin >= 0)
    {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, state);
    }
}
