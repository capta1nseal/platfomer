#ifndef _PLATFORMERAPPLICATION_
#define _PLATFORMERAPPLICATION_


#include "timer.hpp"


/*
Wrapper class for a 2D platforer.
Should contain only initialization, activation and destruction of other components.
*/
class Application
{
public:
    Application();
    ~Application();

    void run();

private:
    bool running_;

    unsigned int tickCount_;

    Timer timer_;
    double tickRate_;
    // 0 for debugging disabled, otherwise number of ticks between debugging outputs.
    // Can be removed for release, but the biggest performance impact comes from printing to terminal.
    const unsigned int debugging_ = 100u;

};


#endif
