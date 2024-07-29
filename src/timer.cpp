#include "timer.hpp"


#include <chrono>
#include <thread>
#include <vector>
#include <numeric>


Timer::Timer()
{
    _lastTick = _clock.now();

    _historyLength = 10u;
    _history.resize(_historyLength, DurationDouble(0.0));
    _historyLocation = 0u;
    _tuningFactor = DurationDouble(0.0001);
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

    if (tickDuration < targetTickDuration)
    {
        std::this_thread::sleep_until(_lastTick + targetTickDuration - _tuningFactor - _tuningFactor);
    }

    // May seem like repeated work, but it guarantees time is always measured at the same point within this function.
    _lastTick = _clock.now();
    tickDuration = _lastTick - lastTick;

    // Update error history, and calculate new average.
    _history[_historyLocation] = tickDuration - targetTickDuration;
    _historyLocation++;
    if (_historyLocation >= _historyLength) _historyLocation = 0;

    _tuningFactor = DurationDouble(0.0);
    for (unsigned int i = 0u; i < _historyLength; i++)
    {
        _tuningFactor += _history[i];
    }
    _tuningFactor = DurationDouble(_tuningFactor.count() / static_cast<double>(_historyLength));

    return tickDuration;
}
