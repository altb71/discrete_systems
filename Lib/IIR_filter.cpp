#include "IIR_filter.h"

// constructors
IIR_filter::IIR_filter(float tau,float Ts)
{
    a0 = -tau/(tau+Ts);
    b0 = Ts/(tau+Ts); 
    y_old = 0;
}
IIR_filter::IIR_filter(float tau,float Ts,float K)
{

}

// Methods:

float IIR_filter::eval(float u)
{
    float y = -a0 * y_old + b0*u;
    y_old = y;
    return y;       // this has to be modified!!!
}


// Deconstructor
IIR_filter::~IIR_filter() {} 