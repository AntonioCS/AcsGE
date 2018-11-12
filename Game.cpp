#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <chrono>
//#include <SDL2/SDL_mixer.h>

#include <sstream>
#include <stdexcept> //std::runtime_error
#include <iostream>
//#include <iostream>

#include "Game.h"
#include "Util/Timer.h"

template<typename... Types>
void throwException(Types... args) {
    std::stringstream ss;
    (ss << ... << args);

    throw std::runtime_error(ss.str());
}

namespace AcsGameEngine {
    Game::Game(std::string windowTitle, std::pair<int, int> windowXY, std::pair<int, int> windowWH)
    : m_gsm(*this)
    {
        m_windowData.windowTitle = windowTitle;
        m_windowData.windowXY = windowXY;
        m_windowData.windowWH = windowWH;
    }

    void Game::Init()
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

        auto[x, y] = m_windowData.windowXY;
        auto[w, h] = m_windowData.windowWH;
        m_window = std::make_unique<Window>(m_windowData.windowTitle, x, y, w, h);

        m_renderer = std::make_unique<Renderer>(*m_window);
    }

    void Game::Cleanup()
    {
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
    }

    void Game::Run()
    {
        // https://gist.github.com/mariobadr/673bbd5545242fcf9482
        using namespace std::chrono_literals;
        using clock = std::chrono::high_resolution_clock;
        using std::chrono::milliseconds;

        Util::Timer timer;
        timer.start();


        constexpr milliseconds timeStep{ 12ms };
        auto accumulator{ 0ms };
        auto frameTime{ 0ms }; //deltaTime I prefer the word frameTime
        if (m_window->isHidden())
        {
            std::cout << "Was hidden\n";
            m_window->showWindow();
        }
        else
        {
            std::cout << "Was not hidden\n";
        }

        while (m_running)
        {
            frameTime = timer.elapsed();
            timer.reset();
            accumulator += frameTime;

            m_eventManager.processEvents();

            if (m_gsm.getCurrentState() == nullptr)
            {
                throw "Current state is a nullptr";
            }

            auto &currentState = *(m_gsm.getCurrentState());

            do
            {
                currentState.update(timeStep);

                accumulator -= timeStep;
            } while (accumulator >= timeStep);

            //m_renderer->Clear(ColorList::white);
            m_renderer->Clear();

            currentState.render(*m_renderer);

            m_renderer->Present();
        }
    }

    bool Game::Running() const noexcept
    {
        return m_running;
    }

    void Game::Quit()
    {
        m_running = false;
    }


    Renderer& Game::getRenderer() const
    {
        return *m_renderer;
    }

    GameStateManager& Game::getGSM()
    {
        return m_gsm;
    }

    EventManager& Game::getEventManager()
    {
        return m_eventManager;
    }

    ECS::EntityManager & Game::getEntityManager()
    {
        return m_entityManager;
    }
}
