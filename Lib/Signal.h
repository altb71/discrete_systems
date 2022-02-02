/*
 * Signal.h
 * Copyright (c) 2017, ZHAW
 * All rights reserved.
 */

#ifndef SIGNAL_H_
#define SIGNAL_H_

#include <cstdlib>
#include <stdint.h>
#include <mbed.h>
#include "rtos.h"
#include <Mutex.h>

/**
 * This class manages the handling of unique signal flags to trigger rtos threads.
 */
class Signal {
    
    public:
        
                        Signal();
        virtual         ~Signal();
        virtual int32_t read();
                        operator int32_t();
        
    private:
        
        static int32_t  signals;    // variable that holds all assigned signal flags
        int32_t         signal;     // signal flag of this object
        Mutex           mutex;      // mutex to lock critical sections
};

#endif /* SIGNAL_H_ */


