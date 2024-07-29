#include "application.hpp"


#include <iostream>
#include <iomanip>

#include "timer.hpp"


Application::Application()
{
    _running = false;
    _tickCount = 0;
    _tickRate = 200.0;
}
Application::~Application()
{
}

void Application::run()
{
    _running = true;
    while (_running)
    {
        DurationDouble tickDuration = _timer.tick(_tickRate);

        // Outputs tick times with a precision down to a microsecond.
        std::cout << "Tick duration:target : " << std::fixed << std::setprecision(6) << tickDuration.count() << ":" << 1.0 / _tickRate << "\n";

        _tickCount++;

        if (_tickCount >= 1000) _running = false;
    }
}
