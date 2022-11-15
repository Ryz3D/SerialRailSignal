#pragma once

#include "deviceIncludes.h"

Vr *vNI = new Vr(65, 286);
Hp *B = new Hp(52, 255);

void setupSignals()
{
    vNI->p_vr1_l = 5;
    vNI->p_vr1_r = 12;
    vNI->p_vr0_l = 6;
    vNI->p_vr0_r = 3;
    vNI->p_kl = 9;

    B->p_hp0_0 = 14;
    B->p_hp1 = 13;
    B->p_hp2 = 19;
    B->p_zs7 = 17;
}

Signal *signals[] = {vNI, B};
