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
    
    while(1) 
    ;    
    

}
