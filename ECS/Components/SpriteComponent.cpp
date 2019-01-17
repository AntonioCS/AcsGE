#include "SpriteComponent.h"
#include "../../Texture.h"
#include <SDL2/SDL.h>

namespace AcsGameEngine::ECS {
    SpriteComponent::SpriteComponent(Sprite *s) : m_sprite(s)
    {
    }
    Sprite *SpriteComponent::getSprite()
    {
        return m_sprite;
    }
}