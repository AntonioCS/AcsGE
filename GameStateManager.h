#pragma once

#include <memory>
#include <unordered_map>
#include "GameState.h"

namespace AcsGameEngine {    
    class Game;
    class EventManager;

    class GameStateManager {
    public:
        GameStateManager(Game &game) : m_game(game) {}
        ~GameStateManager() = default;

        void changeState(const std::string &stateName) {
            if (m_states.find(stateName) != m_states.end())
            {
                m_currentState = m_states[stateName].get();
            }
            else {
                throw std::invalid_argument("State does not exist");
            }
        }

        template<typename GState, typename... GArgs>
        void addState(std::string name, GArgs&& ...gargs) {
            m_states.insert(
                {
                    name,
                    std::make_unique<GState>(*this, std::forward<GArgs>(gargs)...)
                }
            );

            m_currentState = &*(m_states[name]);
            configureCurrentGameState();
        }

        GameState *getCurrentState() const noexcept
        {
            return m_currentState;
        }

        Game &getGame() const noexcept
        {
            return m_game;
        }

    private:
        using GameStateUPtr = std::unique_ptr<GameState>;

        std::unordered_map<std::string, GameStateUPtr> m_states;
        GameState *m_currentState = nullptr;
        Game &m_game;

        void configureCurrentGameState();
    };

}
