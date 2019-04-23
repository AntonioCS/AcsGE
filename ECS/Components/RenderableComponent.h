#pragma once

#include "../Component.h"


namespace AcsGameEngine::ECS {
	class RenderableComponent : public Component {
	public:
		bool visible{ true };
        bool hasBeenRendered{ false };
	};
}