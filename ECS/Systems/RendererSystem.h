#pragma once


#include "../System.h"
#include "../EntityManager.h"
#include "../../Renderer.h"

namespace AcsGameEngine::ECS {

    class RendererSystem : public System
    {
        Renderer &m_renderer;
    public:
        RendererSystem(EntityManager &em, Renderer &renderer);
        ~RendererSystem() = default;

        void init() override;
        void update(std::chrono::milliseconds dt) override;
        void render() override;
	};
}