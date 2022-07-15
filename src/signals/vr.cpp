#include "vr.h"

char Vr::teleType()
{
    return 'V';
}

void Vr::internalSetup()
{
    set(VR0);
}

void Vr::internalSet(uint8_t signal)
{
    switch (signal)
    {
    case KL:
        writePin(p_kl, 1);
        break;
    case VR0:
        writePin(p_vr0_l, 1);
        writePin(p_vr0_r, 1);
        break;
    case VR1:
        writePin(p_vr1_l, 1);
        writePin(p_vr1_r, 1);
        break;
    case VR2:
        writePin(p_vr0_l, 1);
        writePin(p_vr1_r, 1);
        break;
    case OFF:
        writePin(p_kl, 0);
        writePin(p_vr0_l, 0);
        writePin(p_vr0_r, 0);
        writePin(p_vr1_l, 0);
        writePin(p_vr1_r, 0);
        break;
    default:
        break;
    }
}

void Vr::internalLoop() {}
