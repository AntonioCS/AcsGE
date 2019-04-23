
#include "GameState.h"

#include "Game.h"
#include "Window.h"
#include "GameStateManager.h"

namespace AcsGameEngine
{
    void GameState::preUpdate(ms deltaTime)
    {
        getSystemManager().preUpdate(deltaTime);
    }

    void GameState::update(ms deltaTime)
    {
        getSystemManager().update(deltaTime);
    }

    void GameState::postUpdate(ms deltaTime)
    {
        getSystemManager().postUpdate(deltaTime);
    }

    void GameState::preRender()
    {
        getSystemManager().preRender();
    }

    void GameState::render()
    {
        getSystemManager().render();
    }

    void GameState::postRender()
    {
        getSystemManager().postRender();
    }

    void GameState::onLoad()
    {
        init();
        getSystemManager().init();

        m_hasBeenInit = true;
    }

    void GameState::onUnload()
    {
        cleanup();
        //unload events and assets
    }

    void GameState::changeState(std::string newState)
    {
        m_newState = newState;
    }

    bool GameState::hasChangeToNewState() const noexcept
    {
        return !m_newState.empty();
    }

    std::string GameState::getNewStateToChange()
    {
        auto local = m_newState;
        m_newState.clear();
        return local;
    }

#pragma region

    ECS::EntityManager& GameState::getEntityManager()
    {
        return m_entityManager;
    }

    ECS::SystemManager &GameState::getSystemManager()
    {
        return m_systemManager;
    } 

    void GameState::setGameStateManager(GameStateManager *gsm)
    {
        m_gameStateManager = gsm;
    }

    GameStateManager *GameState::getGameStateManager() const
    {
        return m_gameStateManager;
    }


    void GameState::setWindow(Window *window)
    {
        m_window = window;
    }

    Window *GameState::getWindow() const
    {
        return m_window;
    }

    AssetManager* GameState::getAssetManager() const
    {
        return m_assetManager;
    }

    void GameState::setAssetManager(AssetManager* asset_manager)
    {
        m_assetManager = asset_manager;
    }

    EventManager* GameState::getEventManager() const
    {
        return m_eventManager;
    }

    void GameState::setEventManager(EventManager *eventManager)
    {
        m_eventManager = eventManager;
    }
#pragma endregion Getters and Setters
}
