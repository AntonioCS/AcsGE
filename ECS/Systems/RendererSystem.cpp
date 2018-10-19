#include "RendererSystem.h"
#include "../Components/RenderableComponent.h"
#include "../Components/SpriteComponent.h"

namespace AcsGameEngine::ECS {

	RendererSystem::RendererSystem(EntityManager & em, Renderer & renderer) : System(em), m_renderer(renderer) {}

	void RendererSystem::init()
	{
		m_vecRef = m_entityManager.findByComponent<RenderableComponent, SpriteComponent>();
	}

    void RendererSystem::update(std::chrono::milliseconds dt)
	{
	}

	void RendererSystem::render()
	{
		for (const auto ref : m_vecRef) {
			auto &e = ref.get();
			auto state = e.getComponent<RenderableComponent>();

			if (state.isVisible()) {
				m_renderer.DrawSprite(e.getComponent<SpriteComponent>().getSprite());
			}
		}
	}
}