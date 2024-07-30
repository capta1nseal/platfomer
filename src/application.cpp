#include "application.hpp"


#include <iostream>
#include <iomanip>

#include "timer.hpp"


Application::Application()
{
    running_ = false;
    tickCount_ = 0;
    tickRate_ = 200.0;
}
Application::~Application()
{
}

void Application::run()
{
    running_ = true;
    while (running_)
    {
        DurationDouble tickDuration = timer_.tick(tickRate_);

        // Outputs tick times with a precision down to a microsecond.
        

        if (debugging_ != 0u)
        {
            if (tickCount_ % debugging_ == 0)
            {
                std::cout << "Tick " << tickCount_ << "'s duration:target : " << std::fixed << std::setprecision(6) << tickDuration.count() << ":" << 1.0 / tickRate_ << "\n";
            }
        }

        tickCount_++;

        if (tickCount_ > 10000) running_ = false;
    }
}
