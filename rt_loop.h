#pragma once

#include "mbed.h"
#include "Signal.h"
#include "ThreadFlag.h"

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
};
