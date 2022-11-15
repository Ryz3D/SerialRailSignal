#include "sh.h"

char Sh::teleType()
{
    return 'S';
}

const char *Sh::signalType()
{
    return "Sh";
}

uint8_t Sh::fromTeleValue(uint8_t signal)
{
    switch (signal)
    {
    case 0x83:
        return SH_HP0;
    case 0x22:
        return SH_SH1;
    default:
        return OFF;
    }
}

void Sh::internalSet(uint8_t signal)
{
    switch (signal)
    {
    case SH_HP0:
        writePin(p_hp0_0, 1);
        writePin(p_hp0_1, 1);
        break;
    case SH_SH1:
        writePin(p_sh1, 1);
        break;
    case ON:
    case OFF:
        writePin(p_hp0_0, signal == ON);
        writePin(p_hp0_1, signal == ON);
        writePin(p_sh1, signal == ON);
        break;
    default:
        break;
    }
}

void Sh::internalLoop() {}
