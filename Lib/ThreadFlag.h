/*
 * ThreadFlag.h
 * Copyright (c) 2019, ZHAW
 * All rights reserved.
 *
 *  Created on: 29.11.2019
 *      Author: Marcel Honegger
 */

#ifndef THREAD_FLAG_H_
#define THREAD_FLAG_H_

#include <cstdlib>
#include <stdint.h>
#include <mbed.h>

/**
 * This class manages the handling of unique thread flags to trigger rtos threads.
 */
class ThreadFlag {
    
    public:
        
                            ThreadFlag();
        virtual             ~ThreadFlag();
        virtual uint32_t    read();
                            operator uint32_t();
        
    private:
        
        static uint32_t threadFlags;    // variable that holds all assigned thread flags
        uint32_t        threadFlag;     // thread flag of this object
        Mutex           mutex;          // mutex to lock critical sections
};

#endif /* THREAD_FLAG_H_ */

