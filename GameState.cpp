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
}