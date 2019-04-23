#pragma once

#include <memory>
#include <unordered_map>
#include <string>
#include <type_traits>

#include "GameState.h"

namespace AcsGameEngine {    
    class Game;
    class EventManager;

    class GameStateManager {
    public:
        GameStateManager(Game &game) : m_game(game) {}
        ~GameStateManager() = default;

        //void init();
        void changeState(const std::string& stateName);
        void loadState(const std::string& stateName);

        template<typename GState, typename... GArgs>
        GameStateManager *addState(GArgs&& ...gargs) {
            static_assert(std::is_base_of<GameState, GState>::value, "T must inherit from GameState");

            auto newGameState = std::make_unique<GState>(std::forward<GArgs>(gargs)...);
            auto name = newGameState->getName();

            m_states.insert({name, std::move(newGameState)});

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
