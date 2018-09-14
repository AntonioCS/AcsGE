#pragma once

#include <utility> //std::pair

namespace AcsGameEngine::Util {

    struct Dimensions {
        float width;
        float height;

        std::pair<int, int> getWHint() const noexcept
        {
            return {static_cast<int>(width), static_cast<int>(height)};
        }

    };
}