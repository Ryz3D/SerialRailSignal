#pragma once

#include "deviceIncludes.h"

Hp *N101 = new Hp(58, 273);
Hp *N102 = new Hp(59, 270);
Vr *vG = new Vr(63, 282);

void setupSignals()
{
    N101->p_hp0_0 = 10;
    N101->p_hp0_1 = 11;
    N101->p_hp1 = 12;
    N101->p_hp2 = 6;
    N101->p_zs1A = 8;
    N101->p_sh1 = 7;

    N102->p_hp0_0 = 15;
    N102->p_hp0_1 = 14;
    N102->p_hp1 = 13;
    N102->p_zs1A = 17;
    N102->p_sh1 = 18;

    vG->p_vr0_l = 3;
    vG->p_vr1_l = 5;
}

Signal *signals[] = {N101, N102, vG};
