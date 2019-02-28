#pragma once

#include <utility> //std::pair

namespace AcsGameEngine::Util {

    struct Dimensions {
        float width{};
        float height{};

        Dimensions() = default;
        Dimensions(float w, float h) : width(w), height(h) {}
        Dimensions(int w, int h) : Dimensions(static_cast<float>(w), static_cast<float>(h)) {}

        //@TODO add operator*, operator+, operator-, operator/ etc

        Dimensions(const Dimensions &other) : width(other.width), height(other.height) {}

        Dimensions &operator=(const Dimensions &other)
        {
            width = other.width;
            height = other.height;

            return *this;
        }

        std::pair<int, int> getWHint() const noexcept
        {
            return {static_cast<int>(width), static_cast<int>(height)};
        }
    };
}