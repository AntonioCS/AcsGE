#include "Timer.h"
#include <iostream>

namespace AcsGameEngine::Util {

    void Timer::start()
    {
        m_started = true;
        reset();
    }

    void Timer::stop()
    {
        m_started = false;
    }

    void Timer::reset()
    {
        if (isStarted()) {
            m_startTime = clock::now();
        } 
    }

    Timer::ms Timer::elapsed() const noexcept
    {
        if (isStarted()) {            
            const auto elapsed = std::chrono::duration_cast<ms>(clock::now() - m_startTime);

            return elapsed;
        }

        return std::chrono::milliseconds{ 0 };
    }

    bool Timer::isStarted() const noexcept 
    {
        return m_started;
    }
}
