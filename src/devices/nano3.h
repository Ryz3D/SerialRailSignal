#pragma once

#include "deviceIncludes.h"

Hp *A = new Hp(2, 252);
Vr *vA = new Vr(0, 290);
Hp *P2 = new Hp(4, 246);

void setupSignals()
{
    A->p_kl = 10;
    A->p_hp0_0 = 8;
    A->p_hp0_1 = 9;
    A->p_hp1 = 7;
    A->p_hp2 = 12;
    A->p_zs7 = 11;

    vA->p_vr0_l = 5;
    vA->p_vr0_r = 3;
    vA->p_vr1_l = 4;
    vA->p_vr1_r = 2;

    P2->p_kl = 16; // ?
    P2->p_hp0_0 = 18;
    P2->p_hp0_1 = 17;
    P2->p_hp1 = 19;
    P2->p_hp2 = 13;
    P2->p_sh1 = 14;
    P2->p_zs1A = 15; // ?
}

Signal *signals[] = {A, vA, P2};
