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

    void GameState::render(Renderer &renderer)
    {
        loopAction(
            [&renderer](SysPtr &sys) {
                sys.get()->render(renderer);
            }
        );
    }

    GameStateManager & GameState::getGSM() const noexcept
    {
        return m_gameStateManager;
    }
}