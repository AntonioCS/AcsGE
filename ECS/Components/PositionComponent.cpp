#include <utility>
#include "PositionComponent.h"


namespace AcsGameEngine::ECS {
	PositionComponent::PositionComponent(float x, float y) : m_position{x, y}
	{
	}
	Util::Vector2D & PositionComponent::getPosition() noexcept
	{
		return m_position;
	}
}