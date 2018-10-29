#pragma once

#include <chrono>
#include "Entity.h"

namespace AcsGameEngine
{
    class Renderer;
}

namespace AcsGameEngine::ECS {
    using VecEntityRef = std::vector<std::reference_wrapper<Entity>>;

    class EntityManager;

    class System {
    protected:
        VecEntityRef m_vecRef;

    public:
        System() = default;
        virtual ~System() = default;

        virtual void init() = 0;
        virtual void update(std::chrono::milliseconds) = 0;
        virtual void render(Renderer &renderer) = 0;
    };
}
