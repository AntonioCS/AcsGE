#include "EventManager.h"

#include <SDL2/SDL.h>
#include <utility>

namespace AcsGameEngine {
    void EventManager::onMouseClick(eventFunc func) {
        attach(SDL_MOUSEBUTTONUP, std::move(func));
    }

    ///*
    void EventManager::onMouseMove(std::function<void(int, int)> func)
    {
        auto outterFunc = [innerFunc = std::move(func)](SDL_Event &event)
        {
            int x{ 0 };
            int y{ 0 };
            SDL_GetMouseState(&x, &y);

            innerFunc(x, y);

            return true;
        };

        attach(SDL_MOUSEMOTION, std::move(outterFunc));
    }
    //*/

    /*
    void EventManager::onMouseMove(eventFunc func)
    {
        attach(SDL_MOUSEMOTION, std::move(func));
    }
    */

    void EventManager::onKeyDown(eventFunc func, Util::MediatorMultiPriority priority, std::string tag) {
        attach(SDL_KEYDOWN, std::move(func), priority, tag);
    }

    void EventManager::onKeyUp(eventFunc func, Util::MediatorMultiPriority priority, std::string tag) {
        attach(SDL_KEYUP, std::move(func), priority, tag);
    }

    void EventManager::onQuit(eventFunc func, Util::MediatorMultiPriority priority, std::string tag) {
        attach(SDL_QUIT, std::move(func), priority, tag);
    }

    void EventManager::onEvent(const uint32_t eventName, eventFunc func, Util::MediatorMultiPriority priority, std::string tag) {
        attach(eventName, std::move(func), priority, tag);
    }

    void EventManager::processEvents() {
        SDL_Event event;

        while (SDL_PollEvent(&event) != 0) {
            trigger(event.type, event);
        }
    }

    bool EventManager::isKeyPressed(const Uint8 key) {
        const Uint8 *keyState = SDL_GetKeyboardState(nullptr);
        return keyState[key] != 0u;
    }
}  // namespace AcsGameEngine