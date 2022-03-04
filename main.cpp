/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <stdint.h>

#include "IIR_filter.h"
#include "rt_loop.h"

DigitalOut led(LED1);

// main program
static BufferedSerial serial_port(USBTX, USBRX);

int main()
{    serial_port.set_baud(115200);
    serial_port.set_format(8, BufferedSerial::None, 1);
    serial_port.set_blocking(false);
    printf("Start loop\n");
    rt_loop my_loop(.10);
    my_loop.start_theloop();
    while(1) 
    ;    
}
