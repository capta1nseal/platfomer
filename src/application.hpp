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
    bool _running;

    unsigned int _tickCount;

    Timer _timer;
    double _tickRate = 200.0;

};


#endif
