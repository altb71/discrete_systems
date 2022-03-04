#include "IIR_filter.h"
// Altenburger March 2022

// -- 1st order LP filter according to discretisation in lecture 1
IIR_filter::IIR_filter(float tau,float Ts)
{
    a1 = -tau/(tau+Ts);         // shifted to a1, such that the 1st order LP-filter still works
    a0 = 0;                 
    b0 = Ts/(tau+Ts); 
    y_k1 = y_k2 = 0;
}
// 2nd order LP filter according ueb8.pdf from RT1 HS2021 
IIR_filter::IIR_filter(float k,float wb,float D,float Ts)
{
    b0 = k*wb*wb*Ts*Ts;
    a0 = 1.0f + wb*wb*Ts*Ts-2.0f*D*wb*Ts;
    a1 = 2.0f*D*wb*Ts-2.0f;
    y_k1 = y_k2 = 0;
    u_k1 = u_k2 = 0;
}

// Methods:
float IIR_filter::eval(float u)
{
    float y = -a0 * y_k2 - a1 * y_k1 + b0*u_k2;
    y_k2 = y_k1;
    y_k1 = y;
    u_k2 = u_k1;
    u_k1 = u;
    return y;       // this has to be modified!!!
}
// Deconstructor
IIR_filter::~IIR_filter() {} 