#include "vr.h"

char Vr::teleType()
{
    return 'V';
}

const char *Vr::signalType()
{
    return "Vr";
}

void Vr::internalSetup()
{
    set(VR0);
}

void Vr::internalSet(uint8_t signal)
{
    switch (signal)
    {
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
    case ON:
    case OFF:
        writePin(p_vr0_l, signal == ON);
        writePin(p_vr0_r, signal == ON);
        writePin(p_vr1_l, signal == ON);
        writePin(p_vr1_r, signal == ON);
        break;
    default:
        break;
    }
}

void Vr::internalSetTele(uint8_t signal)
{
    switch (signal)
    {
    case 0x60:
        internalSet(VR0);
        break;
    case 0x18:
        internalSet(VR1);
        break;
    case 0x30:
        internalSet(VR2);
        break;
    default:
        internalSet(OFF);
        break;
    }
}

void Vr::internalLoop() {}
