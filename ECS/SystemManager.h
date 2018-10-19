#pragma once

#include <vector>
#include "System.h"

namespace AcsGameEngine::ECS {
    class SystemManager
    {
        std::vector <System> m_systems;
    public:

        void add(System &&system);
        void init();
        void update(float dt);
        void render();
    };
}