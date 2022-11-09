#pragma once

#include "deviceIncludes.h"

Hp *P1 = new Hp(3, 243);
Vr *vN = new Vr(1, 296);
Hp *P3 = new Hp(5, 249);

void setupSignals()
{
    P1->p_kl = 9;
    P1->p_hp0_0 = 11;
    P1->p_hp0_1 = 10;
    P1->p_hp1 = 12;
    P1->p_hp2 = 6;
    P1->p_zs1A = 8;
    P1->p_sh1 = 7;

    vN->p_vr0_l = 2;
    vN->p_vr0_r = 4;
    vN->p_vr1_l = 3;
    vN->p_vr1_r = 5;

    P3->p_kl = 16;
    P3->p_hp0_0 = 18;
    P3->p_hp0_1 = 17;
    P3->p_hp1 = 19;
    P3->p_hp2 = 13;
    P3->p_sh1 = 14;
    P3->p_zs1A = 15;
}

Signal *signals[] = {P1, vN, P3};
