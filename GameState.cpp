#include "GameState.h"
#include "ECS/System.h"

namespace AcsGameEngine
{
    void GameState::init()
    {
        loopAction([](SysRef &sys) {
            sys.get()->init();
        });
    }

    void GameState::update(std::chrono::milliseconds deltaTime)
    {
        loopAction([&deltaTime](SysRef &sys) {
            sys.get()->update(deltaTime);
        });
    }

    void GameState::render()
    {
        loopAction([](SysRef &sys) {
            sys.get()->render();
        });
    }
}
