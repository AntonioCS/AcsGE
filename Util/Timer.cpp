#include "Timer.h"
#include <stdexcept>

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

    Timer::ms Timer::elapsed() const
    {
        if (isStarted()) {
            return Timer::ms{ clock::now() - m_startTime };
        }


        throw std::logic_error{ "Timer not started" };
    }

    bool Timer::isStarted() const noexcept
    {
        return m_started;
    }
}