#ifndef _PLATFORMERTIMER_
#define _PLATFORMERTIMER_


#include <chrono>
#include <thread>
#include <vector>


using SteadyClock = std::chrono::steady_clock;
using DurationDouble = std::chrono::duration<double>;
using TimePointDouble = std::chrono::time_point<SteadyClock, DurationDouble>;


/*
A class encapsulating timing code for loops.
It aims to deliver stable and precise tick times and delta times.
Some tuning is done to correct this_thread::sleep inaccuracy.
Timing will be done in double precision, I see no need to use only float here.
*/
class Timer
{
public:
    Timer();
    ~Timer();

    /*
    To be run once every repetition.
    Attempts to achieve exactly tickRate repetitions in one second.
    Returns the time passed since last call in seconds (double precision, should be good down to a microsecond).
    If the code executed in the loop regularly exceeds the target tick time, target tick rates cannot be achieved.
    */
    DurationDouble tick(double tickRate);

private:
    SteadyClock clock_;
    TimePointDouble lastTick_;

    DurationDouble tuningFactor_;
    double tuningResponsiveness_;

};


#endif
