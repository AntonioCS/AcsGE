#include "ColisionComponent.h"

namespace AcsGameEngine::ECS {
	ColisionComponent::ColisionComponent(int w, int h, bool collidable) : m_w(w), m_h(h), m_collidable(collidable)
	{
	}

	bool ColisionComponent::collidable() const noexcept
	{
		return m_collidable;
	}

	void ColisionComponent::collidable(bool state)
	{
		m_collidable = state;
	}
}