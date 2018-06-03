#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <memory>

namespace AcsGameEngine {

class Renderer;
class Texture;

class Sprite {
private:
    using shaTexture = std::shared_ptr<Texture>;
public:
    Sprite(std::shared_ptr<Texture>);
    Sprite(std::shared_ptr<Texture>, int, int);
    Sprite(std::shared_ptr<Texture>, SDL_Rect, SDL_Rect);
    
    Sprite(const Sprite& orig) = delete;
    Sprite(Sprite&& other);
    virtual ~Sprite();

    void setSourceDestination(SDL_Rect, SDL_Rect);
    void setSource(const SDL_Rect &);

    void setSourceXYWH(int, int, int, int);
    void setDestinationXYWH(int, int, int, int);

    void setSourceXY(int, int);
    void setDestinationXY(int, int);

    void setSourceWH(int, int);
    void setDestinationWH(int, int);

    void setCenter();

    std::pair<int, int> getDestinationPoint() const noexcept;
    SDL_Rect getDestination() const noexcept;
    SDL_Rect getSource() const noexcept;

    shaTexture getTexture() const noexcept;
private:
    shaTexture m_texture;
    SDL_Rect m_destination{ 0, 0, 0, 0 };
    SDL_Rect m_source{ 0, 0, 0, 0 };
};
}
#endif /* SPRITE_H */
