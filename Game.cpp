#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
//#include <SDL2/SDL_mixer.h>

#include <sstream> 
#include <stdexcept> //std::runtime_error
//#include <iostream>

#include "Game.h"

template<typename... Types>
void throwException(Types... args) {
    std::stringstream ss;
    (ss << ... << args);

    throw std::runtime_error(ss.str());
}

namespace AcsGameEngine {

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
        m_window = std::make_unique<Window>(m_windowData.windowTitle,x, y, w, h);

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
        while (m_running)
        {

        }
    }

}
