/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <stdint.h>

#include "IIR_filter.h"
#include "rt_loop.h"

// main program

int main()
{
    
    rt_loop my_loop(1.0);
    my_loop.start_theloop();

    while(1) 
    ;    
    

}
