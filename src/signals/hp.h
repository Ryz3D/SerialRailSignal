#pragma once

#include "signal.h"

#define HP0 0
#define HP1 1
#define HP2 2
#define SH1 3
#define ZS1 4
#define ZS7 5
#define ZS8 6
#define KL 7

class Hp : public Signal
{
public:
    using Signal::Signal;

    char teleType() override;
    const char *signalType() override;
    void internalSetup() override;
    void internalSet(uint8_t signal) override;
    uint8_t transformSignal(uint8_t signal) override;
    void internalLoop() override;

    int8_t p_kl = -1;
    int8_t p_hp0_0 = -1, p_hp0_1 = -1;
    int8_t p_hp1 = -1;
    int8_t p_hp2 = -1;
    int8_t p_sh1 = -1;
    int8_t p_zs1 = -1, p_zs1A = -1, p_zs7 = -1;
};
