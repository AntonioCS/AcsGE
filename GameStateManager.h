#pragma once

#include <memory>
#include <unordered_map>
#include "GameState.h"

namespace AcsGameEngine {    

    class GameStateManager {
        std::unordered_map<
            std::string,
            std::unique_ptr<GameState>
        > m_states;

        GameState *m_currentState = nullptr;
    public:
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
        }

        template<typename GState>
        void addState(std::string name) {
            m_states.insert(
                {
                    name,
                    std::make_unique<GState>(*this)
                }
            );            
        }

        GameState *getCurrentState() const noexcept
        {
            return m_currentState;
        }
    };   
}
