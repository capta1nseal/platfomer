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

};


#endif
