#include "Sprite2.h"

namespace AcsGameEngine {

    Sprite2::Sprite2(Texture* texture) : m_texture(texture)
    {
    }

    Sprite2::Sprite2(Texture* texture, Vector2D position, Size size) 
        : m_texture(texture), m_position(position), m_size(size)
    {
    }

    Texture* Sprite2::getTexture() const
    {
        return m_texture;
    }

    void Sprite2::setTexture(Texture* texture)
    {
        m_texture = texture;
    }

    Vector2D Sprite2::getPosition() const noexcept
    {
        return m_position;
    }

    void Sprite2::setPosition(Vector2D pos)
    {
        m_position = pos;
    }

    Size Sprite2::getSize() const noexcept
    {
        return m_size;
    }

    void Sprite2::setSize(Size size)
    {
        m_size = size;
    }

    void Sprite2::setDestination(const Util::Shapes::Rectangle &destination)
    {
        m_destination = destination;
    }

    Rectangle Sprite2::getDestination() const noexcept
    {
        return m_destination;
    }
}
