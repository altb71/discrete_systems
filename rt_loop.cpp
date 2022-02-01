#include "rt_loop.h"

rt_loop::rt_loop(float Ts)
{
    this->Ts = Ts;
}


void rt_loop::theloop(void)
{
    while(true)
    {
        ThisThread::flags_wait_any(threadFlag);
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
        printf(".");    
    
    }
}

void rt_loop::start_theloop()
{
    thread.start(callback(this, &rt_loop::theloop));
    ticker.attach(callback(this, &rt_loop::sendSignal), Ts);
}

rt_loop::~rt_loop() {}

void rt_loop::sendSignal() {
     thread.flags_set(threadFlag);
}