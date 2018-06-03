
#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
#include <memory>
#include <string>

namespace AcsGameEngine {

class Renderer;

class Texture {
public:
    explicit Texture(SDL_Texture *);
    Texture(const Texture& orig) = delete;

    SDL_Texture* getRawPointer() const;

private:
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> m_texture;    
};
} // namespace AcsGameEngine

#endif /* TEXTURE_H */
