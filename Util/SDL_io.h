#pragma once

#include <SDL2/SDL.h>
#include <iostream>
namespace AcsGameEngine::Util {

    std::ostream& operator<<(std::ostream &os, const SDL_Rect &v) {
        os << "SDL_Rect: x = " << v.x << ", y = " << v.y << ", w = " << v.w << ", h = " << v.h;
        return os;
    }

    std::ostream& operator<<(std::ostream &os, const SDL_Point &v) {
        os << "SDL_Point: x = " << v.x << ", y = " << v.y;
        return os;
    }
}
