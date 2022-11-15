#pragma once

#include "deviceIncludes.h"

Vr *vNII = new Vr(66, 288);
Hp *C = new Hp(53, 258);

void setupSignals()
{
    vNII->p_vr1_l = 5;
    vNII->p_vr1_r = 12;
    vNII->p_vr0_l = 6;
    vNII->p_vr0_r = 3;

    C->p_hp0_0 = 15;
    C->p_hp1 = 13;
    C->p_hp2 = 19;
    C->p_zs7 = 17;
}

Signal *signals[] = {vNII, C};
