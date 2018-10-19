#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <utility> // std::pair
#include "Texture.h"

namespace AcsGameEngine {


    class Sprite {
        const Texture & m_texture;
        SDL_Rect m_source{ 0, 0, 0, 0 };
        SDL_Rect m_destination{ 0, 0, 0, 0 };
        double m_angle{ 0 };
        SDL_RendererFlip m_flip{ SDL_FLIP_NONE };
        SDL_Point m_center;
        std::pair<int, int> m_offSet;

    public:
        Sprite(const Texture &texture, SDL_Rect);
        Sprite(Sprite&& other) noexcept;
        ~Sprite() = default;

        void setSourceDestination(SDL_Rect, SDL_Rect);
        void setSource(const SDL_Rect&);

        void setSourceXYWH(int, int, int, int);
        void setDestinationXYWH(int, int, int, int);

        void setSourceXY(int, int);
        void setDestinationXY(int, int);

        void setSourceWH(int, int);
        void setDestinationWH(int, int);

        void setCenter();

        void angle(double);
        double angle() const noexcept;

        void flip(SDL_RendererFlip);
        SDL_RendererFlip flip() const noexcept;

        void centerPoint(SDL_Point);
        SDL_Point centerPoint() const noexcept;

        std::pair<int, int> getDestinationPoint() const noexcept;
        SDL_Rect getDestination() const noexcept;
        SDL_Rect getSource() const noexcept;

        void setOffSet(int x, int y) noexcept;
        std::pair<int, int> getOffSet() const noexcept;

        const Texture& getTexture() const noexcept;
    };
}  // namespace AcsGameEngine
#endif /* SPRITE_H */
