#include "signal.h"

Signal::Signal(uint8_t channel, uint16_t dcc_address)
{
    this->channel = channel;
    this->dcc_address = dcc_address;
}

void Signal::setup()
{
    internalSet(0);
}

void Signal::set(uint8_t value)
{
    last_value = value;
    blink_state = 1;
    last_blink = millis();
    internalSet(OFF);
    internalSet(value);

    Serial.print(signalType());
    Serial.print(" (");
    Serial.print(dcc_address);
    Serial.print(") set to ");
    Serial.print(value);
    Serial.println();
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

void Signal::internalSet(uint8_t signal)
{
    Serial.println("Signal::internalSet not implemented!");
}

uint8_t Signal::fromTeleValue(uint8_t signal)
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
