/*
 * ThreadFlag.cpp
 * Copyright (c) 2019, ZHAW
 * All rights reserved.
 *
 *  Created on: 29.11.2019
 *      Author: Marcel Honegger
 */

#include "ThreadFlag.h"

using namespace std;

uint32_t ThreadFlag::threadFlags = 0;

/**
 * Creates a signal object and assignes a unique flag.
 */
ThreadFlag::ThreadFlag() {
    
    mutex.lock();
    
    uint32_t n = 0;
    while ((((1 << n) & threadFlags) > 0) && (n < 30)) n++;
    threadFlag = (1 << n);
    
    mutex.unlock();
}

/**
 * Deletes the signal object and releases the assigned flag.
 */
ThreadFlag::~ThreadFlag() {
    
    mutex.lock();
    
    threadFlags &= ~threadFlag;
    
    mutex.unlock();
}

/**
 * Gets the assigned thread flag.
 */
uint32_t ThreadFlag::read() {
    
    return threadFlag;
}

/**
 * The empty operator is a shorthand notation of the <code>read()</code> method.
 */
ThreadFlag::operator uint32_t() {
    
    return read();
}

