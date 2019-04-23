#pragma once

#include "../Component.h"
#include "../../Sprite.h"

namespace AcsGameEngine::ECS {
    class SpriteComponent : public Component
    {
    public:
        SpriteComponent() = default;
        SpriteComponent(Sprite *s);
        ~SpriteComponent() = default;

        void update(Sprite *s);
        Sprite *getSprite();
    private:
        Sprite *m_sprite;
    };
}
