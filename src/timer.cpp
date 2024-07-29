#include "timer.hpp"


#include <chrono>
#include <thread>
#include <vector>
#include <numeric>


Timer::Timer()
{
    lastTick_ = clock_.now();

    tuningFactor_ = DurationDouble(0.0);
    tuningResponsiveness_ = 0.1;
}
Timer::~Timer()
{
}

std::chrono::duration<double> Timer::tick(double tickRate)
{
    TimePointDouble lastTick = lastTick_;
    lastTick_ = clock_.now();
    DurationDouble tickDuration = lastTick_ - lastTick;

    DurationDouble targetTickDuration = DurationDouble(1.0 / tickRate);

    if (tickDuration < targetTickDuration)
    {
        std::this_thread::sleep_until(lastTick_ + (targetTickDuration - tuningFactor_));
    }

    // May seem like repeated work, but it guarantees time is always measured at the same point within this function.
    lastTick_ = clock_.now();
    tickDuration = lastTick_ - lastTick;

    tuningFactor_ = tuningFactor_ + tuningResponsiveness_ * (tickDuration - targetTickDuration);

    return tickDuration;
}
