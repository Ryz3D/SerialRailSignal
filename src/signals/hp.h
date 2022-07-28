#pragma once

#include "signal.h"

#define KL 0
#define HP0 1
#define HP1 2
#define HP2 3
#define SH1 4
#define ZS1 5
#define ZS7 6
#define ZS8 7

class Hp : public Signal
{
public:
    using Signal::Signal;

    char teleType() override;
    void internalSetup() override;
    void internalSet(uint8_t signal) override;
    void internalLoop() override;

    int8_t p_kl = -1;
    int8_t p_hp0_0 = -1, p_hp0_1 = -1;
    int8_t p_hp1 = -1;
    int8_t p_hp2 = -1;
    int8_t p_zs1_0 = -1, p_zs1_1 = -1, p_zs1_2 = -1;
    int8_t p_zs7_0 = -1, p_zs7_1 = -1, p_zs7_2 = -1;
};
