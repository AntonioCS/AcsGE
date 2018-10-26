#pragma once

//#include <SDL2/SDL.h>
#include <functional>
#include <string>
#include "Util/Mediator.h"

union SDL_Event;

namespace AcsGameEngine {
    using Util::Mediator;
    using eventFunc = std::function<void(SDL_Event &event)>;

    class EventManager {
    public:
        void onMouseClick(eventFunc func);

        void onKeyDown(eventFunc func);

		void onKeyUp(eventFunc func);

        void onQuit(eventFunc func);

        void onEvent(const uint32_t eventName, eventFunc func);

        void processEvents(const std::string &nameSpace = "Global");

        bool isKeyPressed(const uint8_t key);

    private:
        std::unordered_map<
            std::string,
            std::unordered_map<uint32_t, bool>
        > m_toTrigger;
    };
} //namespace AcsGameEngine
