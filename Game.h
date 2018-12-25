#pragma once

#include <string>
#include <memory>

#include "AssetManager.h"
#include "EventManager.h"
#include "ECS/EntityManager.h"

namespace AcsGameEngine {
    class Renderer;
    class Window;
    class GameStateManager;
    class AssetManager;

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

        Renderer *getRenderer() const;
        Window *getWindow() const;
        GameStateManager *getGSM();
        EventManager *getEventManager();
        ECS::EntityManager *getEntityManager();
        AssetManager *getAssetManager();

    private:
        struct WindowData
        {
            std::string windowTitle;
            std::pair<int, int> windowXY;
            std::pair<int, int> windowWH;
        } m_windowData;

        std::unique_ptr<Window> m_window;
        std::unique_ptr<Renderer> m_renderer;
        std::unique_ptr<GameStateManager> m_gameStateManager;
        EventManager m_eventManager;
        ECS::EntityManager m_entityManager;
        AssetManager m_assetManager;

        bool m_running{ true };
    };
}
