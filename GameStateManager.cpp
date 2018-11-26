#include "GameStateManager.h"
#include "Game.h"

namespace AcsGameEngine {

    void GameStateManager::configureCurrentGameState()
    {
        m_currentState->setGameStateManager(this);
        m_currentState->setRenderer(m_game.getRenderer());
        m_currentState->setWindow(m_game.getWindow());
    }
}