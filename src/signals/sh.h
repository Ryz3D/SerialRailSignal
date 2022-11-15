#pragma once

#include "signal.h"

#define SH_HP0 0
#define SH_SH1 1

class Sh : public Signal
{
public:
    using Signal::Signal;

    char teleType() override;
    const char *signalType() override;
    uint8_t fromTeleValue(uint8_t signal) override;
    void internalSet(uint8_t signal) override;
    void internalLoop() override;

    int8_t p_hp0_0 = -1, p_hp0_1 = -1;
    int8_t p_sh1 = -1;
};
