#include "hp.h"

char Hp::teleType()
{
    return 'S';
}

void Hp::internalSetup()
{
    set(HP0);
}

void Hp::internalSet(uint8_t signal)
{
    switch (signal)
    {
    case KL:
        writePin(p_zs1_0, 1);
        break;
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
    case ZS1:
        writePin(p_zs1_0, 1);
        writePin(p_zs1_1, 1);
        writePin(p_zs1_2, 1);
        break;
    case ZS7:
        writePin(p_zs7_0, 1);
        writePin(p_zs7_1, 1);
        writePin(p_zs7_2, 1);
        break;
    case OFF:
        writePin(p_hp0_0, 0);
        writePin(p_hp0_1, 0);
        writePin(p_hp1, 0);
        writePin(p_hp2, 0);
        writePin(p_zs1_0, 0);
        writePin(p_zs1_1, 0);
        writePin(p_zs1_2, 0);
        writePin(p_zs7_0, 0);
        writePin(p_zs7_1, 0);
        writePin(p_zs7_2, 0);
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
        if (p_zs1_1 == -1)
            writePin(p_zs1_0, blink_state);
        break;
    case ZS8:
        writePin(p_zs1_0, blink_state);
        writePin(p_zs1_1, blink_state);
        writePin(p_zs1_2, blink_state);
        break;
    default:
        break;
    }
}
