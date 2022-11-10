#include "hp.h"

char Hp::teleType()
{
    return 'S';
}

const char *Hp::signalType()
{
    return "Hp";
}

uint8_t Hp::fromTeleValue(uint8_t signal)
{
    switch (signal)
    {
    case 0x00:
        return KL;
    case 0x03:
    case 0x83:
        return HP0;
    case 0x08:
        return HP1;
    case 0x0C:
        return HP2;
    case 0x22:
        return SH1;
    case 0x13:
        return ZS1;
    case 0x43:
        return ZS8;
    default:
        return OFF;
    }
}

void Hp::internalSet(uint8_t signal)
{
    switch (signal)
    {
    case HP0:
        writePin(p_hp0_0, 1);
        writePin(p_hp0_1, 1);
        break;
    case HP1:
        writePin(p_hp1, 1);
        break;
    case HP2:
        writePin(p_hp1, 1);
        writePin(p_hp2, 1);
        break;
    case SH1:
        writePin(p_sh1, 1);
        writePin(p_hp0_0, 1);
        break;
    case ZS1:
        if (p_zs1A >= 0)
            writePin(p_zs1A, 1);
        else if (p_zs1 == -1 && p_zs7 >= 0)
            internalSet(ZS7);
        writePin(p_hp0_0, 1);
        break;
    case ZS7:
        if (p_zs7 >= 0)
            writePin(p_zs7, 1);
        else
            internalSet(ZS1);
        writePin(p_hp0_0, 1);
        break;
    case ZS8:
        writePin(p_hp0_0, 1);
        break;
    case KL:
        if (p_kl >= 0)
            writePin(p_kl, 1);
        else
            writePin(p_zs1, 1);
        break;
    case ON:
    case OFF:
        writePin(p_kl, signal == ON);
        writePin(p_hp0_0, signal == ON);
        writePin(p_hp0_1, signal == ON);
        writePin(p_hp1, signal == ON);
        writePin(p_hp2, signal == ON);
        writePin(p_zs1, signal == ON);
        writePin(p_zs1A, signal == ON);
        writePin(p_zs7, signal == ON);
        writePin(p_sh1, signal == ON);
        break;
    default:
        break;
    }
}

void Hp::internalLoop()
{
    switch (last_value)
    {
    case ZS1:
        if (p_zs1A == -1)
            writePin(p_zs1, blink_state);
        break;
    case ZS8:
        writePin(p_zs1A, blink_state);
        break;
    default:
        break;
    }
}
