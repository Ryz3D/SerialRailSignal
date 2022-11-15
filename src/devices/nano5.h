#pragma once

#include "deviceIncludes.h"

Vr *vC = new Vr(62, 292);

void setupSignals()
{
    vC->p_vr1_l = 5;
    vC->p_vr1_r = 12;
    vC->p_vr0_l = 3;
    vC->p_vr0_r = 6;
    vC->p_kl = 9;
}

Signal *signals[] = {vC};
