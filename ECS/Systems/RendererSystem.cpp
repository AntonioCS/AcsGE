#include "RendererSystem.h"
#include "../../Game.h"
#include "../../Renderer.h"
#include "../EntityManager.h"
#include "../Components/RenderableComponent.h"
#include "../Components/SpriteComponent.h"
#include "../Components/Shapes/CircleComponent.h"
#include "../../Util/Drawer.h"

namespace AcsGameEngine::ECS {
    void RendererSystem::init()
    {
        m_vecRef = getEntityManager()->findByComponent<RenderableComponent>();
    }

    void RendererSystem::update(std::chrono::milliseconds dt)
    {
    }

    ///void RendererSystem::render(Renderer &renderer)
    void RendererSystem::render()
    {
        for (const auto ref : m_vecRef) {
            auto &e = ref.get();
            auto &state = e.getComponent<RenderableComponent>();
            if (state.visible) {
                
            }
            /*
            if (state.isVisible()) {
                if (e.hasComponent<SpriteComponent>())
                {
                    renderer.drawSprite(e.getComponent<SpriteComponent>().getSprite());
                }
                else {
                    Util::Drawer drawer{ renderer };

                    if (e.hasComponent<CircleComponent>())
                    {
                        CircleComponent &cicleComponent = e.getComponent<CircleComponent>();
                    }
                }
            }*/
        }
    }
}