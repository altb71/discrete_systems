#include "rt_loop.h"
#include "mbed.h"
#include "EncoderCounter.h"

#define PI 3.1415927

// get hardware access (these are defined in main.cpp) via "extern" (global variable). This is not a "nice" solution.
// we will do that a little better later on.
extern DigitalOut led;
extern EncoderCounter enc1;
extern EncoderCounter enc2;
extern AnalogOut i_des1;
extern AnalogOut i_des2;
extern DigitalIn big_button;
extern DigitalOut i_enable;

rt_loop::rt_loop(float Ts)
{
    this->Ts = Ts;
    dif1.setup(.01,Ts);         // time constant of diff filter should be larger (less fast) than Ts
    dif2.setup(.01,Ts);         
    i2u.setup(-.8,.8,0,1);      // map desired currrents. The inverse of this function is on the current controller
}


void rt_loop::theloop(void)
{
    uint8_t k=0;
    while(true)
    {
        ThisThread::flags_wait_any(threadFlag);
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
        led = !led;
        short c1 = enc1;        // read encoder 1
        short c2 = enc2;
        float w1 = dif1((float)c1*2*PI/4000.0f);
        float w2 = dif2((float)c2*2*PI/4000.0f);
        if(++k==0)          // make printouts only every 256th step!
            printf("%d %d %f %f\r\n",c1,c2,w1,w2);
        if(k>128)       // this is just "one" solution! Put desired current to motor 1 first, then to motor 2 
            {
            i_des1.write(i2u(.3));
            i_des2.write(i2u(0));
            }
        else
             {
            i_des1.write(i2u(0));
            i_des2.write(i2u(0.3));
            }
       i_enable = big_button;       // map the "enable" button to the enabling of current controllers
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