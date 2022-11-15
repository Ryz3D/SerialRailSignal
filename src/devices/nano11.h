#pragma once

#include "deviceIncludes.h"

Hp *G = new Hp(54, 276);
Hp *H13 = new Hp(69, 279);
Vr *vP = new Vr(64, 284);

void setupSignals()
{
    G->p_hp0_0 = 10;
    G->p_hp1 = 12;
    G->p_zs7 = 8;
    G->p_kl = 9;

    H13->p_hp0_0 = 3;
    H13->p_hp1 = 5;
    H13->p_zs1A = 4;
    H13->p_sh1 = 18;

    vP->p_vr0_l = 19;
    vP->p_vr0_r = 14;
    vP->p_vr1_l = 13;
    vP->p_vr1_r = 15;
    vP->p_kl = 16;
}

Signal *signals[] = {G, H13, vP};
