#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <chrono>
//#include <SDL2/SDL_mixer.h>

#include <sstream>
#include <stdexcept> //std::runtime_error
#include <exception>

#include "Game.h"
#include "Renderer.h"
#include "Window.h"
#include "GameStateManager.h"
#include "Util/Timer.h"
#include "Util/ColorList.h"
#include "KeyboardManager.h"

template<typename... Types>
void throwException(Types... args) {
    std::stringstream ss;
    (ss << ... << args);

    throw std::runtime_error(ss.str());
}

namespace AcsGameEngine {
    Game::Game(std::string windowTitle, Util::Vector2D windowXY, Util::Size windowWH)
    {
        m_windowData.windowTitle = windowTitle;
        m_windowData.windowXY = windowXY;
        m_windowData.windowWH = windowWH;
    }

    void Game::init()
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            throwException("Unable to initialize SDL: ", SDL_GetError());
        }

        const int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
        if ((IMG_Init(imgFlags) & imgFlags) == 0) {
            throwException("SDL_image could not initialize! SDL_image Error: ", IMG_GetError());
        }

        if (TTF_Init() == -1) {
            throwException("SDL_ttf could not initialize! SDL_ttf Error: ", TTF_GetError());
        }

        auto[x, y] = m_windowData.windowXY.getXYint();
        auto[w, h] = m_windowData.windowWH.getWHint();

        m_window = std::make_unique<Window>(m_windowData.windowTitle, x, y, w, h);
        m_renderer = std::make_unique<Renderer>(*m_window);
        m_gameStateManager = std::make_unique<GameStateManager>(*this);
        m_assetManager.setRenderer(&*m_renderer);
    }

    void Game::cleanup()
    {
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
    }

    void Game::run()
    {
        // https://gist.github.com/mariobadr/673bbd5545242fcf9482
        using namespace std::chrono_literals;
        using clock = std::chrono::high_resolution_clock;
        using std::chrono::milliseconds;

        constexpr auto timeStep{ 16ms };
        constexpr Util::Timer::ms maxAccumulator{ 250ms };
        Util::Timer::ms accumulator{ 0ms };
        auto frameTime{ 0ms }; //deltaTime I prefer the word frameTime
        Util::Timer timer;

        if (m_window->isHidden()) {
            m_window->showWindow();
        }

        registerGameEvents();

        timer.start();

        while (m_running)
        {
            auto currentGameState = getCurrentGameState();

            accumulator += timer.elapsed();
            timer.reset();

            m_eventManager.processEvents();

            while (accumulator >= timeStep) {
                currentGameState->preUpdate(timeStep);
                currentGameState->update(timeStep);
                currentGameState->postUpdate(timeStep);

                accumulator -= timeStep;

                if (accumulator >= maxAccumulator) {
                    accumulator = 0ms;
                }
            }

            m_renderer->clear(m_clearColor);

            currentGameState->preRender();
            currentGameState->render();
            currentGameState->postRender();

            m_renderer->present();

            if (currentGameState->hasChangeToNewState()) {
                m_gameStateManager->changeState(currentGameState->getNewStateToChange());
            }
        }
    }

    bool Game::running() const noexcept
    {
        return m_running;
    }

    void Game::quit()
    {
        m_running = false;
    }

    Util::Color Game::getClearColor() const noexcept
    {
        return m_clearColor;
    }

    void Game::setClearColor(Util::Color c)
    {
        m_clearColor = c;
    }

    Renderer *Game::getRenderer() const
    {
        return m_renderer.get();
    }

    Window *Game::getWindow() const
    {
        return m_window.get();
    }

    GameStateManager *Game::getGameStateManager() const
    {
        return m_gameStateManager.get();
    }

    EventManager *Game::getEventManager()
    {
        return &m_eventManager;
    }

    ECS::EntityManager *Game::getEntityManager()
    {
        return &m_entityManager;
    }

    AssetManager* Game::getAssetManager()
    {
        return &m_assetManager;
    }

    GameState* Game::getCurrentGameState() const
    {
        const auto currentState = m_gameStateManager->getCurrentState();

        if (currentState == nullptr) {
            throw std::runtime_error{ "Current game state is a null" };
        }

        return currentState;
    }

    void Game::registerGameEvents()
    {
        constexpr auto critical = Util::MediatorMultiPriority::critical;

        m_eventManager.onQuit([this](SDL_Event &event) {
            quit();
            return true;
        }, critical);


        auto &km = KeyboardManager::getInstance();

        m_eventManager.onKeyDown([&km](SDL_Event& e)
        {
            km.onKeyDown(e);
            return true;
        }, critical);

        m_eventManager.onKeyUp([&km](SDL_Event& e)
        {
            km.onKeyUp(e);
            return true;
        }, critical);

        m_eventManager.onEvent(SDL_MOUSEBUTTONDOWN, [](SDL_Event &event)
        {
            return true;
        }, critical);

        m_eventManager.onEvent(SDL_MOUSEBUTTONUP, [](SDL_Event &event)
        {
            return true;
        }, critical);

        m_eventManager.onEvent(SDL_MOUSEMOTION, [](SDL_Event &event)
        {
            return true;
        }, critical);

        m_eventManager.onEvent(SDL_MOUSEWHEEL, [](SDL_Event &event)
        {
            return true;
        }, critical);
    }
}
