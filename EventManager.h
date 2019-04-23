#pragma once

//#include <SDL2/SDL.h>
#include <functional>
#include <string>
//#include "Util/Mediator.h"
#include "Util/MediatorMulti.h"

union SDL_Event;

namespace AcsGameEngine {
    //using Util::Mediator;
    using Util::MediatorMulti;
    //using eventFunc = std::function<void(SDL_Event &event)>;
    using eventFunc = std::function<bool(SDL_Event &event)>;

    //class EventManager : public Mediator<uint32_t, eventFunc> {
    class EventManager : public MediatorMulti<uint32_t, eventFunc> {
    public:
        void onMouseClick(eventFunc func);
        //void onMouseMove(eventFunc func);
        void onMouseMove(std::function<void(int, int)> func);

        void onKeyDown(eventFunc func, Util::MediatorMultiPriority priority = Util::MediatorMultiPriority::normal, std::string tag = std::string{ Util::MediatorMultiDefaultValues::tag });

		void onKeyUp(eventFunc func, Util::MediatorMultiPriority priority = Util::MediatorMultiPriority::normal, std::string tag = std::string{ Util::MediatorMultiDefaultValues::tag });

        void onQuit(eventFunc func, Util::MediatorMultiPriority priority = Util::MediatorMultiPriority::normal, std::string tag = std::string{ Util::MediatorMultiDefaultValues::tag });

        void onEvent(const uint32_t eventName, eventFunc func, Util::MediatorMultiPriority priority = Util::MediatorMultiPriority::normal, std::string tag = std::string{ Util::MediatorMultiDefaultValues::tag });

        void processEvents();

        bool isKeyPressed(const uint8_t key);

    private:
        std::unordered_map<
            std::string,
            std::unordered_map<uint32_t, bool>
        > m_toTrigger;
    };
} //namespace AcsGameEngine
