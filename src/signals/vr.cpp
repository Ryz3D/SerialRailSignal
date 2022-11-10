#include "vr.h"

char Vr::teleType()
{
    return 'V';
}

const char *Vr::signalType()
{
    return "Vr";
}

uint8_t Vr::fromTeleValue(uint8_t signal)
{
    switch (signal)
    {
    case 0x60:
        return VR0;
    case 0x18:
        return VR1;
    case 0x30:
        return VR2;
    default:
        return OFF;
    }
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

void Vr::internalLoop() {}
