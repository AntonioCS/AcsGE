#pragma once

//#include <SDL2/SDL.h>
#include <functional>
#include "Util/Mediator.h"

union SDL_Event;

namespace AcsGameEngine {

    class EventManager : public AcsGameEngine::Util::Mediator<uint32_t, std::function<void(SDL_Event &event)>> {
        using eventFunc = std::function<void(SDL_Event &event)>;
    public:
        void onMouseClick(eventFunc func);

        void onKeyDown(eventFunc func);

		void onKeyUp(eventFunc func);

        void onQuit(eventFunc func);

        void onEvent(uint32_t eventName, eventFunc func);

        void processEvents();

        bool isKeyPressed(uint8_t key);
    };
} //namespace AcsGameEngine
