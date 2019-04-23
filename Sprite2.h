#pragma once

#include "Util/Vector2D.h"
#include "Util/Size.h"
#include "Util/Shapes/Rectangle.h"

namespace AcsGameEngine {
    class Texture;

    using Util::Size;
    using Util::Vector2D;
    using Util::Shapes::Rectangle;

    class Sprite2 {        
    public:
        Sprite2() = default;
        Sprite2(Texture *texture);
        Sprite2(Texture *texture, Vector2D position, Size size);
        //Sprite2(Sprite2&& other) noexcept;
        ~Sprite2() = default;

        Texture *getTexture() const;
        void setTexture(Texture *texture);

        Vector2D getPosition() const noexcept;
        void setPosition(Vector2D pos);

        Size getSize() const noexcept;
        void setSize(Size size);

        void setDestination(const Rectangle& destination);
        Rectangle getDestination() const noexcept;

    private:
        Texture *m_texture{nullptr};
        Vector2D m_position{};
        Size m_size{};
        Util::Shapes::Rectangle m_destination{};
        //std::pair<int, int> m_offSet;
    };
}
