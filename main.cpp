/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <stdint.h>

#include "IIR_filter.h"

DigitalOut led(LED1);

// main program
static BufferedSerial serial_port(USBTX, USBRX);

int main()
{    serial_port.set_baud(115200);
    serial_port.set_format(
        /* bits */ 8,
        /* parity */ BufferedSerial::None,
        /* stop bit */ 1);
    serial_port.set_blocking(false);
    printf("Start loop\n");
    const int N = 100;
    float y[N];
    float u[N];
    IIR_filter LP(.1,0.01);
    for(uint16_t k = 0;k<N;k++)
        u[k] = 1*(k>=10);           // step response, set first 10 values =0
    for(uint16_t k = 0;k<N;k++)
        y[k] = LP(u[k]);
    for(uint16_t k = 0;k<N;k++)
        printf("%2.4f %2.4f\r\n",u[k],y[k]);
    while(1) 
    ;    
    

}
