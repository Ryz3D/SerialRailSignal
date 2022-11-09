#pragma once

#include <Arduino.h>
#include "settings.h"

#define ON 254
#define OFF 255

class Signal
{
public:
    Signal(uint8_t channel, uint16_t dcc_address);

    void setup();
    void set(uint8_t signal, bool tele = false);
    void loop();
    virtual char teleType();
    virtual const char *signalType();

    uint8_t channel = 0;
    uint16_t dcc_address = 0;
    uint8_t last_value = OFF;

protected:
    virtual void internalSetup();
    virtual void internalSet(uint8_t signal);
    virtual void internalSetTele(uint8_t signal);
    virtual void internalLoop();

    void writePin(int8_t pin, bool state);

    uint64_t blink_delay = 500;
    bool blink_state = 0;

private:
    uint64_t last_blink = 0;
};
