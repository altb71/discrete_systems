/*
 * Signal.cpp
 * Copyright (c) 2017, ZHAW
 * All rights reserved.
 */

#include "Signal.h"

using namespace std;

int32_t Signal::signals = 0;

/**
 * Creates a signal object and assignes a unique flag.
 */
Signal::Signal() {
    
    mutex.lock();
    
    int32_t n = 0;
    while ((((1 << n) & signals) > 0) && (n < 30)) n++;
    signal = (1 << n);
    
    mutex.unlock();
}

/**
 * Deletes the signal object and releases the assigned flag.
 */
Signal::~Signal() {
    
    mutex.lock();
    
    signals &= ~signal;
    
    mutex.unlock();
}

/**
 * Gets the assigned signal flag.
 */
int32_t Signal::read() {
    
    return signal;
}

/**
 * The empty operator is a shorthand notation of the <code>read()</code> method.
 */
Signal::operator int32_t() {
    
    return read();
}


