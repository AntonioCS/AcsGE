#include "CollisionComponent.h"
#include "../../Util/Shapes/Shape.h"

namespace AcsGameEngine::ECS {
    CollisionComponent::CollisionComponent(Shape& shape, bool collidable) : m_shape(shape)
    {
    }

    bool CollisionComponent::collidable() const noexcept
	{
		return m_collidable;
	}

	void CollisionComponent::collidable(bool state)
	{
		m_collidable = state;
	}
}