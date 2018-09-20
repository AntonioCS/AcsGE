#pragma once

#include "../Component.h"


namespace AcsGameEngine::Util::Shapes
{
    class Shape;
}

namespace AcsGameEngine::ECS {
    using AcsGameEngine::Util::Shapes::Shape;

	class CollisionComponent : public Component
	{
        Shape &m_shape;
		bool m_collidable{ true };

	public:
        CollisionComponent(Shape &shape, bool collidable = true);
        ~CollisionComponent() = default;

		bool collidable() const noexcept;
		void collidable(bool state);
	};
}

