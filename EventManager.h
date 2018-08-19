#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL.h>
#include <functional>
#include "Util/Mediator.h"

namespace AcsGameEngine {

    class EventManager : public AcsGameEngine::Util::Mediator<Uint32, std::function<void(SDL_Event &event)>> {        
        SDL_Event m_event{};
        using eventFunc = std::function<void(SDL_Event &event)>;
    public:
        void onMouseClick(eventFunc func);

        void onKeyDown(eventFunc func);

		void onKeyUp(eventFunc func);

        void onQuit(eventFunc func);

        void onEvent(Uint32 eventName, eventFunc func);

        void processEvents();

        bool isKeyPressed(Uint8 key);
    };
} //namespace AcsGameEngine

#endif
