#pragma once


#include "../System.h"

//#include "../EntityManager.h"
//#include "../../Renderer.h"

namespace AcsGameEngine
{
    class Renderer;
}


namespace AcsGameEngine::ECS {

    class RendererSystem : public System
    {
    public:
        void init() override;
        void update(std::chrono::milliseconds dt) override;
        void render(Renderer &renderer) override;
	};
}