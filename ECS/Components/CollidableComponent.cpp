#include "CollidableComponent.h"
#include "../../Sprite.h"

namespace AcsGameEngine::ECS {
    CollidableComponent::CollidableComponent(float x, float y, float w, float h) : m_box(
        AcsGameEngine::Util::Vector2D{ x, y },
        AcsGameEngine::Util::Dimensions{ w, h }
    )
    {
    }

    CollidableComponent::CollidableComponent(const Sprite* s): m_box(
        AcsGameEngine::Util::Vector2D{s->getDestination().x, s->getDestination().y},
        AcsGameEngine::Util::Dimensions{s->getDestination().w, s->getDestination().h}
    )
    {
    }

    bool CollidableComponent::drawRect() const noexcept
    {
        return true;
    }

    void CollidableComponent::updateOrigin(float x, float y)
    {
        m_box.origin.x = x;
        m_box.origin.y = y;
    }

    void CollidableComponent::updateDimension(float w, float h)
    {
        m_box.dimensions.width = w;
        m_box.dimensions.height = h;
    }

    void CollidableComponent::update(float x, float y, float w, float h)
    {
        updateOrigin(x, y);
        updateDimension(w, h);
    }

    void CollidableComponent::update(AcsGameEngine::Util::Vector2D vec)
    {
        m_box.origin = vec;
    }

    void CollidableComponent::update(AcsGameEngine::Util::Dimensions dim)
    {
        m_box.dimensions = dim;
    }

    AcsGameEngine::Util::Shapes::Rectangle& CollidableComponent::getRect()
    {
        return m_box;
    }

    bool CollidableComponent::isColliding(AcsGameEngine::Util::Shapes::Rectangle& otherShape) const
    {
        return m_collision.checkCollision(m_box, otherShape);
    }
}
