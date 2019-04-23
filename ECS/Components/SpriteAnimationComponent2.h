#pragma once

#include "../Component.h"
#include "../../SpriteAnimationManager.h"

namespace AcsGameEngine::ECS {

    class SpriteAnimationComponent2 : public Component
    {
    public:
        SpriteAnimationManager spriteAnimationManager;
    };
}