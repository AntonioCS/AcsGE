#pragma once

#include <chrono>
#include <functional>
#include <algorithm>

#include "ECS/System.h"

namespace AcsGameEngine
{
    class GameStateManager;
    class Renderer;
    class EventManager;

    class GameState
    {
    public:
        GameState(GameStateManager& gsm) : m_gameStateManager(gsm)
        {
        }

        virtual ~GameState() = default;

        virtual void init();
        virtual void handleEvents();
        virtual void update(std::chrono::milliseconds deltaTime);
        virtual void render(Renderer &renderer);

    protected:
        using SysPtr = std::unique_ptr<ECS::System>;
        using SysFunc = std::function<void(SysPtr &sys)>;
    private:
        GameStateManager& m_gameStateManager;
        std::vector<SysPtr> m_systems;
    protected:
        GameStateManager &getGSM() const noexcept;

        void loopAction(SysFunc func)
        {
            std::for_each(
                std::begin(m_systems),
                std::end(m_systems),
                func
            );
        }
    };
}
