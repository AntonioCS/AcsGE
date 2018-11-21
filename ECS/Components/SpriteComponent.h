#pragma once

#include "../Component.h"
#include "../../Sprite.h"
#include "../../Util/Shapes/Rectangle.h"

namespace AcsGameEngine::ECS {
    class SpriteComponent : public Component
    {
        Sprite m_sprite;
    public:
        SpriteComponent(Texture &texture, AcsGameEngine::Util::Shapes::Rectangle rect, int x, int y);
        ~SpriteComponent() = default;

        Sprite &getSprite();
    };
}
