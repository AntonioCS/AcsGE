#pragma once

#include "../Component.h"
#include "../../Sprite.h"
#include <SDL2/SDL.h>

namespace AcsGameEngine::ECS {
	class ColisionComponent : public Component
	{
		int m_w;
		int m_h;

		bool m_collidable{ true };

	public:
		ColisionComponent(int w, int h, bool collidable = true);
		~ColisionComponent() = default;

		bool collidable() const noexcept;
		void collidable(bool state);
	};
}

