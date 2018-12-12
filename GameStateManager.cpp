#include "GameStateManager.h"
#include "Game.h"

#include <algorithm>

namespace AcsGameEngine {
    void GameStateManager::init()
    {
        std::for_each(
            std::begin(m_states),
            std::end(m_states),
            [](std::pair<const std::string, GameStateUPtr> &p)
            //[](auto &p)
            {
                p.second->init();
            }
        );
    }

    GameState* GameStateManager::getCurrentState() const noexcept
    {
        return m_currentState;
    }

    Game& GameStateManager::getGame() const noexcept
    {
        return m_game;
    }

    void GameStateManager::configureCurrentGameState()
    {
        m_currentState->setGameStateManager(this);
        m_currentState->setRenderer(m_game.getRenderer());
        m_currentState->setWindow(m_game.getWindow());
    }
}