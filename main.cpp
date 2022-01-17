/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <stdint.h>

#include "IIR_filter.h"

// main program

int main()
{
    const uint16_t N = 100;
    float u[N],y[N];
    const float Ts = .001;
    IIR_filter fi(.01,Ts);              // fi is an IIR_filter object
    for(uint16_t k=0;k<N;++k)
        u[k] = 1.0;
    for(uint16_t k=0;k<N;++k)
        y[k] = fi(u[k]);
// ------------------------------------
    printf("Step response\r\n");
    for(uint16_t k=0;k<N;++k)
        printf("%f %f\r\n",u[k],y[k]);

    while(1) 
    ;    
    



}
