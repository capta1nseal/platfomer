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
    Returns the time passed in seconds (double precision, should be good down to a microsecond).
    If the code executed in the loop regularly exceeds the target tick time, target tick rates cannot be achieved.
    */
    DurationDouble tick(double tickRate);

private:
    SteadyClock _clock;
    TimePointDouble _lastTick;

    std::vector<DurationDouble> _history;
    // Stores the errors for the last _historyLength ticks. Used as a queue indexed by _historyLocation.
    unsigned int _historyLength;
    // Location within _history to treat as "head" of history queue.
    unsigned int _historyLocation;
    // Double-precision time in milliseconds used to minimise errors in tick length.
    DurationDouble _tuningFactor;

};


#endif
