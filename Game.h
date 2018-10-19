#pragma once

#include <string>
#include <memory>

#include "Renderer.h"
#include "Window.h"

//#include "EventManager.h"
//#include "ECS/EntityManager.h"

#include "GameStateManager.h"

namespace AcsGameEngine {

    class Game
    {
    public:
        GameStateManager gsm;
        
        Game(std::string windowTitle, std::pair<int,int> windowXY, std::pair<int,int> windowWH)
        {   
            m_windowData.windowTitle = windowTitle;
            m_windowData.windowXY = windowXY;
            m_windowData.windowWH = windowWH;
        }

        ~Game() = default;


        void Init();
        void Cleanup();

        void Run();

        bool Running() const noexcept
        {
            return m_running;
        }
        void Quit()
        {
            m_running = false;
        }

    private:
        struct WindowData
        {
            std::string windowTitle;
            std::pair<int, int> windowXY;
            std::pair<int, int> windowWH;
        } m_windowData;

        std::unique_ptr<Window> m_window;
        std::unique_ptr <Renderer> m_renderer;

        bool m_running{ false };
    };
}
