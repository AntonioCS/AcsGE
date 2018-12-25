#include "Game.h"
#include "GameState.h"
#include "GameStateManager.h"
#include "Renderer.h"
#include "ECS/System.h"

namespace AcsGameEngine
{
    void GameState::init()
    {
        loopAction(
            [](SysPtr &sys) {
                sys.get()->init();
            }
        );
    }

    void GameState::handleEvents()
    {
    }

    void GameState::update(std::chrono::milliseconds deltaTime)
    {
        loopAction(
            [&deltaTime](SysPtr &sys) {
                sys.get()->update(deltaTime);
            }
        );
    }

    void GameState::render()
    {
     /*   loopAction(
            [&renderer](SysPtr &sys) {
                sys.get()->render(renderer);
            }
        );
        */
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
}
