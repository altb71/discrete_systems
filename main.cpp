/* 
    Project "discrete_systems" according week 1 - week 3 in spring semester 2022
    altb@zhaw.ch
 */

#include "mbed.h"
#include <stdint.h>

#include "IIR_filter.h"

static BufferedSerial serial_port(USBTX, USBRX);
// main program

int main()
{    serial_port.set_baud(115200);
    serial_port.set_format(8, BufferedSerial::None, 1);
    serial_port.set_blocking(false);
    const int N = 100;
    float y[N];
    float u[N];
    IIR_filter LP(2.0, 15, 0.7, 0.01);      // initialize LP filter with value k, wb, D, Ts
    for(uint16_t k = 0;k<N;k++)
        u[k] = 1*(k>=10);           // step response, set first 10 values =0
    for(uint16_t k = 0;k<N;k++)
        y[k] = LP(u[k]);            // do the step N times
    for(uint16_t k = 0;k<N;k++)
        printf("%2.4f %2.4f\r\n",u[k],y[k]);
    // run into infinite loop
    while(1) 
        ;
}
