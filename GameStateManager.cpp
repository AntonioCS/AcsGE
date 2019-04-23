#include "GameStateManager.h"
#include "Game.h"
#include "ECS/SystemManager.h"

#include <algorithm>

namespace AcsGameEngine {

    //WARNING: Do not use directly from GameState
    void GameStateManager::changeState(const std::string& stateName)
    {
        const auto res = m_states.find(stateName);

        if (res != m_states.end()) {
            if (m_currentState != nullptr) {
                m_currentState->onUnload();
            }

            m_currentState = &*(res->second);
            configureCurrentGameState();

            m_currentState->onLoad();
        }
        else {
            throw std::invalid_argument("State does not exist");
        }
    }

    void GameStateManager::loadState(const std::string& stateName)
    {
        changeState(stateName);
    }
    /*
    void GameStateManager::init()
    {
        std::for_each(
            std::begin(m_states),
            std::end(m_states),
            [](std::pair<const std::string, GameStateUPtr> &p)
            {
                p.second->init();
            }
        );
    }
    */
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
        m_currentState->setAssetManager(m_game.getAssetManager());
        m_currentState->setEventManager(m_game.getEventManager());

        m_currentState
            ->getSystemManager()
                .setup(
                    m_game.getRenderer(), 
                    m_game.getWindow(), 
                    &(m_currentState->getEntityManager()),
                    m_currentState
                );
    }
}