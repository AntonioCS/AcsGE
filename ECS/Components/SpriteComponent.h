#pragma once

#include "../Component.h"
#include "../../Sprite.h"

namespace AcsGameEngine::ECS {
    class SpriteComponent : public Component
    {
    public:
        SpriteComponent(Sprite *s);
        ~SpriteComponent() = default;

        Sprite *getSprite();
    private:
        Sprite *m_sprite;
    };
}
