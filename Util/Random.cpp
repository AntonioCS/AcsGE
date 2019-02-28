#include "Random.h"

int AcsGameEngine::Util::Random::RandomIntBetween(int min, int max) noexcept
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    const std::uniform_int_distribution<> dis(min, max);

    return dis(gen);
}
