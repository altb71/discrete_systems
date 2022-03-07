/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <stdint.h>

#include "IIR_filter.h"
#include "rt_loop.h"
#include "EncoderCounter.h"

// define outputs
DigitalOut led(LED1);
DigitalOut i_enable(PC_4);
AnalogOut i_des1(PA_5);
AnalogOut i_des2(PA_4);

// define inputs
DigitalIn big_button(PC_3);
EncoderCounter enc1(PA_6,PC_7);
EncoderCounter enc2(PB_6,PB_7);

// main program
static BufferedSerial serial_port(USBTX, USBRX);

int main()
{    serial_port.set_baud(115200);
    serial_port.set_format(8, BufferedSerial::None, 1);
    serial_port.set_blocking(false);
    printf("Start loop\n");
    rt_loop my_loop(.001);
    my_loop.start_theloop();
    while(1) 
    ;    
}
