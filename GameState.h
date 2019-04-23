#pragma once

#include <chrono>

#include "Uses/UsesRenderer.h"
#include "ECS/EntityManager.h"
#include "ECS/SystemManager.h"

namespace AcsGameEngine
{
    class GameStateManager;
    class EventManager;
    class AssetManager;
    class Window;

    class GameState : public Uses::UsesRenderer
    {
    protected:
        using ms = std::chrono::milliseconds;
    public:
        GameState() = default;
        virtual ~GameState() = default;

        virtual void init() = 0;
        virtual void cleanup() = 0;
        virtual std::string getName() const noexcept = 0;

        //virtual void handleEvents();

        virtual void preUpdate(ms deltaTime);
        virtual void update(ms deltaTime);
        virtual void postUpdate(ms deltaTime);

        virtual void preRender();
        virtual void render();
        virtual void postRender();

        virtual void onLoad();
        virtual void onUnload();

        void changeState(std::string newState);
        bool hasChangeToNewState() const noexcept;
        std::string getNewStateToChange();

        void setGameStateManager(GameStateManager *gsm);
        void setWindow(Window *window);
        void setAssetManager(AssetManager* asset_manager);
        void setEventManager(EventManager *eventManager);
        GameStateManager *getGameStateManager() const;
        Window *getWindow() const;
        AssetManager* getAssetManager() const;
        EventManager *getEventManager() const;

        ECS::EntityManager &getEntityManager();
        ECS::SystemManager &getSystemManager();

    private:
        GameStateManager *m_gameStateManager{nullptr};
        AssetManager *m_assetManager{nullptr};
        EventManager *m_eventManager{nullptr};
        Window *m_window{nullptr};

    protected:
        ECS::EntityManager m_entityManager;
        ECS::SystemManager m_systemManager;
        std::string m_newState{};
        bool m_hasBeenInit{ false };

    };
}
