#pragma once

#include "deviceIncludes.h"

Sh *Ls102 = new Sh(56, 298);
Hp *P103 = new Hp(57, 261);
Hp *N103 = new Hp(60, 267);

void setupSignals()
{
    Ls102->p_hp0_0 = 3;
    Ls102->p_hp0_1 = 5;
    Ls102->p_sh1 = 4;

    P103->p_hp0_0 = 10;
    P103->p_hp0_1 = 11;
    P103->p_hp1 = 12;
    P103->p_hp2 = 6;
    P103->p_zs1A = 8;
    P103->p_sh1 = 7;

    N103->p_hp0_0 = 15;
    N103->p_hp0_1 = 14;
    N103->p_hp1 = 13;
    N103->p_hp2 = 19;
    N103->p_zs1A = 17;
    N103->p_sh1 = 18;
}

Signal *signals[] = {Ls102, P103, N103};
