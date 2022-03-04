#ifndef IIR_FILTER_H_
#define IIR_FILTER_H_

#include "mbed.h"

class IIR_filter
{

public:

    IIR_filter(float T, float Ts);                                            // G(s) = s/(T*s + 1)
    IIR_filter(float T, float Ts, float K);                                   // G(s) = K/(T*s + 1)
    IIR_filter(float w0, float D, float Ts, float K);                         // G(s) = K*w0^2/(s^2 + 2*D*w0*s + w0^2)
    IIR_filter(float wz, float Dz, float wp, float Dp, float Ts, float K);    // G(s) = K * wp^2/wz^2 * (s^2 + 2*Dz*wz*s + wz^2)/(s^2 + 2*Dp*wp*s + wp^2)
    IIR_filter(float *b, float *a, int nb, int na);                           // G(z) = B(z) / A(z) = (b_0 + b_1*z^-1 + ... + b_nb*z^-nb) / (1 + a_1*z^-1 + ... + a_na*z^-na)

    IIR_filter() {};

    virtual ~IIR_filter();

    void    setup(float T, float Ts);                                         // G(s) = s/(T*s + 1)
    void    setup(float T, float Ts, float K);                                // G(s) = K/(T*s + 1)
    void    setup(float w0, float D, float Ts, float K);                      // G(s) = K*w0^2/(s^2 + 2*D*w0*s + w0^2)
    void    setup(float wz, float Dz, float wp, float Dp, float Ts, float K); // G(s) = K * wp^2/wz^2 * (s^2 + 2*Dz*wz*s + wz^2)/(s^2 + 2*Dp*wp*s + wp^2)
    void    setup(float *b, float *a, int nb, int na);                        // G(z) = B(z) / A(z) = (b_0 + b_1*z^-1 + ... + b_nb*z^-nb) / (1 + a_1*z^-1 + ... + a_na*z^-na)

    void    reset();
    void    reset(float u);
    void    reset(float u, float y);

    void    set_limits(float yMax);
    void    set_limits(float yMin, float yMax);

    float   filter(float u);

    float   get_output();

    float operator()(float u)
    {
        return filter(u);
    }

    float   prewarp(float T, float Ts);

    void    print_filter_coeff();

private:

    uint8_t nb, na;
    float   *B;
    float   *A;
    float   *uk;
    float   *yk;
    float   K;
    float   yMin, yMax;

    float   saturate(float y, float yMin, float yMax);

};
#endif