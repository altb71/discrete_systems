#pragma once
#include <stdint.h>

/* class IIR-filter
Constructors:
...(float tau,float Ts)                     // 1st order LP-filter in ZOH trafo
...(float k, float wb, float D, float Ts)   // 2nd        "          with gain K

methods:
eval(float u)       // make one step iteration with input u
operator: (float)   // calls "eval" 
*/
class IIR_filter
{
public:
    IIR_filter(float,float);
    IIR_filter(float,float,float,float);
    virtual ~IIR_filter();
    float eval(float);
    float operator()(float u){
            return eval((float)u);
         }
private:
    float *B;
    float *A;
    uint8_t nb,na;
    float b0,a0,a1,y_k1,y_k2,u_k1,u_k2;
};