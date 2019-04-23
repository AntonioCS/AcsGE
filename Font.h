#pragma once

#include <SDL2/SDL_ttf.h>
#include <memory>

namespace AcsGameEngine {
    class Font
    {
    public:
        Font();
        Font(TTF_Font *);

        TTF_Font * getRawPointer() const;
    private:
        std::unique_ptr<TTF_Font, decltype(&TTF_CloseFont)> m_fontPtr;
    };
}