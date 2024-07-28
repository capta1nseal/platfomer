#include "application.hpp"


#include <iostream>

#include "timer.hpp"


Application::Application()
{
    _running = false;
    _tickCount = 0;
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

        std::cout << "Tick duration:target : " << tickDuration.count() << ":" << 1.0 / _tickRate << "\n";

        _tickCount++;

        if (_tickCount >= 1000) _running = false;
    }
}