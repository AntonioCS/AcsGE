#pragma once

#include <string>
#include <memory>

#include "AssetManager.h"
#include "EventManager.h"
#include "ECS/EntityManager.h"
#include "Util/Vector2D.h"
#include "Util/Size.h"


namespace AcsGameEngine {
    class Renderer;
    class Window;
    class GameStateManager;
    class GameState;
    class AssetManager;

    class Game
    {
    public:
        //Game(std::string windowTitle);
        Game(std::string windowTitle, Util::Vector2D windowXY, Util::Size windowWH);
        ~Game() = default;

        void init();
        void cleanup();
        void run();
        bool running() const noexcept;
        void quit();

        Util::Color getClearColor() const noexcept;
        void setClearColor(Util::Color);

        Renderer *getRenderer() const;
        Window *getWindow() const;
        GameStateManager *getGameStateManager() const;
        EventManager *getEventManager();
        ECS::EntityManager *getEntityManager();
        AssetManager *getAssetManager();

        GameState *getCurrentGameState() const;

    private:
        void registerGameEvents();

    private:
        struct WindowData {
            std::string windowTitle;
            Util::Vector2D windowXY;
            Util::Size windowWH;
        } m_windowData;

        std::unique_ptr<Window> m_window;
        std::unique_ptr<Renderer> m_renderer;
        std::unique_ptr<GameStateManager> m_gameStateManager;
        EventManager m_eventManager;
        ECS::EntityManager m_entityManager;
        AssetManager m_assetManager;

        bool m_running{ true };
        bool m_windowCentered{ false };

        Util::Color m_clearColor{ Util::ColorList::white };

    };
}
