#include "timer.hpp"


#include <chrono>
#include <thread>


Timer::Timer()
{
    _lastTick = _clock.now();
}
Timer::~Timer()
{
}

std::chrono::duration<double> Timer::tick(double tickRate)
{
    TimePointDouble lastTick = _lastTick;
    _lastTick = _clock.now();
    DurationDouble tickDuration = _lastTick - lastTick;

    DurationDouble targetTickDuration = DurationDouble(1.0 / tickRate);

    if (tickDuration >= targetTickDuration) return tickDuration;

    if (tickDuration < targetTickDuration)
    {
        std::this_thread::sleep_until(_lastTick + targetTickDuration);
    }

    _lastTick = _clock.now();
    tickDuration = _lastTick - lastTick;

    return tickDuration;
}
