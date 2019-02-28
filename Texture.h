#pragma once

#include <SDL2/SDL.h>
#include <memory>

namespace AcsGameEngine {
    class Texture {
    public:
        Texture();
        Texture(SDL_Texture*);

        SDL_Texture* getRawPointer() const;

    private:
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> m_texturePtr;
    };
} // namespace AcsGameEngine
