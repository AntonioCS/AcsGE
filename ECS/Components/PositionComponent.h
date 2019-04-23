#pragma once

#include "../Component.h"
#include "../../Sprite.h"
#include "../../Util/Vector2D.h"
#include <SDL2/SDL.h>

namespace AcsGameEngine::ECS {
    class PositionComponent : public Component
    {
        using Vector2D = Util::Vector2D;
    public:
        PositionComponent() = default;
        PositionComponent(float x, float y);
        PositionComponent(int x, int y);
        PositionComponent(Util::Vector2D vec);
        ~PositionComponent() = default;

        Vector2D &getPosition() noexcept;
        void setPosition(const float x, const float y);
        void setPosition(const Vector2D &vec);
    private:
        Vector2D m_position;
    };
}
