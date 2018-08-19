#include "RenderableComponent.h"
namespace AcsGameEngine::ECS {
	RenderableComponent::RenderableComponent()
	{
	}

	RenderableComponent::RenderableComponent(bool state) : m_visible(state)
	{
	}

	bool RenderableComponent::isVisible() const noexcept
	{
		return m_visible;
	}

	void RenderableComponent::setVisiableState(bool state)
	{
		m_visible = state;
	}
}