#pragma once

#include <memory>
#include <unordered_map>
#include <string>
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

        void init();

        template<typename GState, typename... GArgs>
        GameStateManager *addState(std::string name, GArgs&& ...gargs) {
            m_states.insert(
                {
                    name,
                    std::make_unique<GState>(std::forward<GArgs>(gargs)...)
                }
            );

            m_currentState = &*(m_states[name]);
            configureCurrentGameState();

            return this;
        }

        GameState* getCurrentState() const noexcept;

        Game& getGame() const noexcept;

    private:
        using GameStateUPtr = std::unique_ptr<GameState>;

        std::unordered_map<std::string, GameStateUPtr> m_states;
        GameState *m_currentState = nullptr;
        Game &m_game;

        void configureCurrentGameState();
    };

}
