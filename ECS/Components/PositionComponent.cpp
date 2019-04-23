#include <utility>
#include "PositionComponent.h"

namespace AcsGameEngine::ECS {
    PositionComponent::PositionComponent(float x, float y) : m_position{ x, y }
    {
    }

    PositionComponent::PositionComponent(int x, int y) : PositionComponent(static_cast<float>(x), static_cast<float>(y))
    {
    }

    PositionComponent::PositionComponent(Util::Vector2D vec) : m_position(vec)
    {
        
    }

    Util::Vector2D & PositionComponent::getPosition() noexcept
    {
        return m_position;
    }

    void PositionComponent::setPosition(const float x, const float y)
    {
        m_position.x = x;
        m_position.y = y;
    }

    void PositionComponent::setPosition(const Vector2D &vec)
    {
        m_position = vec;
    }
}
