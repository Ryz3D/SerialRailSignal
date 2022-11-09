#pragma once

#include "deviceIncludes.h"

Hp *F = new Hp(9, 231);
Vr *vF = new Vr(11, 303);
Hp *N2 = new Hp(7, 237);

void setupSignals()
{
    F->p_kl = 10;
    F->p_hp0_0 = 8;
    F->p_hp0_1 = 9;
    F->p_hp1 = 7;
    F->p_hp2 = 12;
    F->p_zs7 = 11;

    vF->p_vr0_l = 5;
    vF->p_vr0_r = 3;
    vF->p_vr1_l = 4;
    vF->p_vr1_r = 2;

    N2->p_kl = 16;
    N2->p_hp0_0 = 18;
    N2->p_hp0_1 = 17;
    N2->p_hp1 = 19;
    N2->p_hp2 = 13;
    N2->p_sh1 = 14;
    N2->p_zs1A = 15;
}

Signal *signals[] = {F, vF, N2};
