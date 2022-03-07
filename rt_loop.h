#pragma once

#include "mbed.h"
#include "Signal.h"
#include "ThreadFlag.h"
#include "IIR_filter.h"
#include "LinearCharacteristics.h"
class rt_loop
{
public:
    rt_loop(float);
    void start_theloop(void);
    virtual ~rt_loop();
private:
    void theloop(void);
    Thread thread;
    Ticker ticker;
    ThreadFlag threadFlag;
    Signal signal;
    void sendSignal();
    Timer ti;
    float Ts;
    IIR_filter dif1,dif2;
    LinearCharacteristics i2u;      // define LC to map currents to the analog output
};
