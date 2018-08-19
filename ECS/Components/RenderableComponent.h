#pragma once

#include "../Component.h"
#include "../../Sprite.h"
#include <SDL2/SDL.h>

namespace AcsGameEngine::ECS {
	class RenderableComponent : public Component {
		bool m_visible{ true };
	public:
		RenderableComponent();
		RenderableComponent(bool state);

		bool isVisible() const noexcept;
		void setVisiableState(bool state);
	};
}