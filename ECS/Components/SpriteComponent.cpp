#include "SpriteComponent.h"
#include <utility>
#include "../../Texture.h"

namespace AcsGameEngine::ECS {
	SpriteComponent::SpriteComponent(Texture &texture, SDL_Rect s, int x, int y) : m_sprite(texture, s)
	{
		getSprite().setDestinationXY(x, y);
	}
	Sprite & SpriteComponent::getSprite()
	{
		return m_sprite;
	}
}