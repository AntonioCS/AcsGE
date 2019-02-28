#pragma once

#include <chrono>

namespace AcsGameEngine::Util {
    class Timer {
    public:
        using clock = std::chrono::steady_clock;
        using tPoint = std::chrono::time_point<clock>;
        using ms = std::chrono::duration<double>;

        void start();
        void stop();
        void reset();
        ms elapsed() const;
        bool isStarted() const noexcept;
    private:
        bool m_started{ false };
        tPoint m_startTime;
    };
}