#pragma once

#include <chrono>
#include <functional>
#include <algorithm>

#include "ECS/System.h"

namespace AcsGameEngine
{
    class GameStateManager;

    class GameState
    {
        using SysRef = const std::unique_ptr<ECS::System>;
        using SysFunc = std::function<void(const std::unique_ptr<ECS::System>& sys)>;

        GameStateManager& m_gameStateManager;
        std::vector<std::unique_ptr<ECS::System>> m_systems;
    protected:
        void loopAction(SysFunc func)
        {
            std::for_each(
                std::begin(m_systems),
                std::end(m_systems),
                func
            );
        }
    public:
        GameState(GameStateManager& gsm) : m_gameStateManager(gsm)
        {
        }

        virtual ~GameState() = default;

        virtual void init();
        virtual void update(std::chrono::milliseconds deltaTime);
        virtual void render();
    };
}
