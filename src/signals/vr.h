#pragma once

#include "signal.h"

#define KL 0
#define VR0 1
#define VR1 2
#define VR2 3

class Vr : public Signal
{
public:
    using Signal::Signal;

    char teleType() override;
    void internalSetup() override;
    void internalSet(uint8_t signal) override;
    void internalLoop() override;

    int8_t p_kl = -1;
    int8_t p_vr0_l = -1, p_vr0_r = -1;
    int8_t p_vr1_l = -1, p_vr1_r = -1;
};
