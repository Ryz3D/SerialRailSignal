#pragma once

#include "deviceIncludes.h"

// TODO: existiert signal 12?

Sh *LsB = new Sh(69, 295);
Hp *P101 = new Hp(55, 264);

void setupSignals()
{
    LsB->p_hp0_0 = 3;
    LsB->p_sh1 = 4;

    P101->p_hp0_0 = 10;
    P101->p_hp0_1 = 11;
    P101->p_hp1 = 12;
    P101->p_hp2 = 6;
    P101->p_zs1A = 8;
    P101->p_sh1 = 7;
}

Signal *signals[] = {LsB, P101};
