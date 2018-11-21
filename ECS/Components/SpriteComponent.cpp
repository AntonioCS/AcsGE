#include "SpriteComponent.h"
#include "../../Texture.h"
#include <SDL2/SDL.h>

namespace AcsGameEngine::ECS {
    SpriteComponent::SpriteComponent(Texture &texture, AcsGameEngine::Util::Shapes::Rectangle rect, int x, int y)
        : m_sprite(texture, SDL_Rect{ static_cast<int>(rect.origin.x), static_cast<int>(rect.origin.y), static_cast<int>(rect.dimensions.width), static_cast<int>(rect.dimensions.height) })
    {
        getSprite().setDestinationXY(x, y);
    }
    Sprite & SpriteComponent::getSprite()
    {
        return m_sprite;
    }
}