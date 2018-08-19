#pragma once

#include "../Component.h"
#include "../../Sprite.h"
#include "../../Util/Vector2D.h"
#include <SDL2/SDL.h>

namespace AcsGameEngine::ECS {
	class PositionComponent : public Component
	{
		Util::Vector2D m_position;
	public:
		PositionComponent(float x, float y);
		~PositionComponent() = default;
		
		Util::Vector2D &getPosition() noexcept;
	};
}
