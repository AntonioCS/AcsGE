#include "RendererSystem.h"
#include "../../Game.h"
#include "../../Renderer.h"
#include "../EntityManager.h"
#include "../Components/RenderableComponent.h"
#include "../Components/SpriteComponent.h"

namespace AcsGameEngine::ECS {

    void RendererSystem::init()
    {
        m_vecRef = getEntityManager().findByComponent<RenderableComponent, SpriteComponent>();
    }

    void RendererSystem::update(std::chrono::milliseconds dt)
    {
    }

    void RendererSystem::render(Renderer &renderer)
    {
        for (const auto ref : m_vecRef) {
            auto &e = ref.get();
            auto state = e.getComponent<RenderableComponent>();

            if (state.isVisible()) {
                renderer.DrawSprite(e.getComponent<SpriteComponent>().getSprite());
            }
        }
    }
}