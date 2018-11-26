#pragma once

#include <chrono>
#include <functional>
#include <algorithm>

#include "ECS/System.h"

namespace AcsGameEngine
{
    class GameStateManager;
    class Renderer;
    class Window;
    class EventManager;

    class GameState
    {
    public:
        GameState() = default;
        virtual ~GameState() = default;

        virtual void init();
        virtual void handleEvents();
        virtual void update(std::chrono::milliseconds deltaTime);
        virtual void render();

        void setGameStateManager(GameStateManager *gsm)
        {
            m_gameStateManager = gsm;
        }

        void setRenderer(Renderer *renderer)
        {
            m_renderer = renderer;
        }

        void setWindow(Window *window)
        {
            m_window = window;
        }

        GameStateManager *getGameStateManager() const
        {
            return m_gameStateManager;
        }

        Renderer *getRenderer() const
        {
            return m_renderer;
        }

        Window *getWindow() const
        {
            return m_window;
        }

    protected:
        using SysPtr = std::unique_ptr<ECS::System>;
        using SysFunc = std::function<void(SysPtr &sys)>;

        GameStateManager &getGSM() const noexcept;

        void loopAction(SysFunc func)
        {
            std::for_each(
                std::begin(m_systems),
                std::end(m_systems),
                func
            );
        }
    private:
        GameStateManager *m_gameStateManager;
        Renderer *m_renderer;
        Window *m_window;
        std::vector<SysPtr> m_systems;
    };
}
