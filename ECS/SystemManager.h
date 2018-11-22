#pragma once

#include <vector>
#include <memory>
#include "System.h"

namespace AcsGameEngine::ECS {
    class SystemManager
    {
    public:
        template<typename T, typename... TArgs>
        T& addSystem(TArgs&&... mArgs) {
            m_systems.push_back(std::make_unique<T>(std::forward<TArgs>(mArgs)...));
            return static_cast<T&>(*m_systems.back());
        }

        void init();
        void update(float dt);
        void render();
    private:
        std::vector <std::unique_ptr<System>> m_systems;
    };
}