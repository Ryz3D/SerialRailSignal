#pragma once

#include "deviceIncludes.h"

Hp *N1 = new Hp(6, 234);
Vr *vP = new Vr(10, 299);
Hp *N3 = new Hp(8, 240);

void setupSignals()
{
    N1->p_kl = 9;
    N1->p_hp0_0 = 7;
    N1->p_hp0_1 = 8;
    N1->p_hp1 = 6;
    N1->p_hp2 = 12;
    N1->p_sh1 = 11;
    N1->p_zs1A = 10;

    vP->p_vr0_l = 5;
    vP->p_vr0_r = 3;
    vP->p_vr1_l = 4;
    vP->p_vr1_r = 2;

    N3->p_kl = 16;
    N3->p_hp0_0 = 18;
    N3->p_hp0_1 = 17;
    N3->p_hp1 = 19;
    N3->p_hp2 = 13;
    N3->p_sh1 = 14;
    N3->p_zs1A = 15;
}

Signal *signals[] = {N1, vP, N3};
