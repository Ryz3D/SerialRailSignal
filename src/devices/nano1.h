#pragma once

#include "deviceIncludes.h"

Hp *F = new Hp(1, 2);
// Vr *vF = new Vr(2, 3);

void setupSignals()
{
    F->p_kl = 13;
    F->p_hp0_0 = 2;
    F->p_hp0_1 = 3;
    F->p_hp1 = 4;
    F->p_zs1_0 = 5;

    /*
        vF->p_vr0_l = 6;
        vF->p_vr0_r = 8;
        vF->p_vr1_l = 7;
        vF->p_vr1_r = 9;
        vF->p_kl = 10;
    */
}

Signal *signals[] = {F /*, vF*/};
