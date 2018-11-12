#pragma once

#include <string>
#include <memory>

#include "Renderer.h"
#include "Window.h"
#include "EventManager.h"
#include "ECS/EntityManager.h"

#include "GameStateManager.h"

namespace AcsGameEngine {

    class Game
    {
    public:
        Game(std::string windowTitle, std::pair<int, int> windowXY, std::pair<int, int> windowWH);
        ~Game() = default;

        void Init();
        void Cleanup();
        void Run();
        bool Running() const noexcept;
        void Quit();

        Renderer &getRenderer() const;
        GameStateManager &getGSM();
        EventManager &getEventManager();
        ECS::EntityManager &getEntityManager();

    private:
        GameStateManager m_gsm;

        struct WindowData
        {
            std::string windowTitle;
            std::pair<int, int> windowXY;
            std::pair<int, int> windowWH;
        } m_windowData;

        std::unique_ptr<Window> m_window;
        std::unique_ptr <Renderer> m_renderer;
        EventManager m_eventManager;
        ECS::EntityManager m_entityManager;

        bool m_running{ true };
    };
}
