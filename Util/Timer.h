#pragma once

#include <chrono>

namespace AcsGameEngine::Util {
    
    class Timer {
        using clock = std::chrono::high_resolution_clock;
        using tPoint = std::chrono::time_point<clock>;      
        using ms = std::chrono::milliseconds;

        bool m_started{ false };
        tPoint m_startTime;
    public:
        Timer() = default;
        ~Timer() = default;

        void start();
        void stop();
        void reset();
        ms elapsed() const noexcept;
        bool isStarted() const noexcept;
    };
}