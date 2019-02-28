#pragma once

#include <random>

namespace AcsGameEngine::Util {

    class Random
    {
    public:
        static int RandomIntBetween(int min, int max) noexcept;
    };
}