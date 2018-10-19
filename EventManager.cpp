#include "EventManager.h"

#include <SDL2/SDL.h>
#include <utility>

namespace AcsGameEngine {

    void EventManager::onMouseClick(eventFunc func) {
        attach(SDL_MOUSEBUTTONUP, std::move(func));
    }

    void EventManager::onKeyDown(eventFunc func) {
        attach(SDL_KEYDOWN, std::move(func));
    }

	void EventManager::onKeyUp(eventFunc func) {
        attach(SDL_KEYUP, std::move(func));
    }

    void EventManager::onQuit(eventFunc func) {
        attach(SDL_QUIT, std::move(func));
    }

    void EventManager::onEvent(Uint32 eventName, eventFunc func) {
        attach(eventName, std::move(func));
    }

    void EventManager::processEvents() {
        SDL_Event event;

        while (SDL_PollEvent(&event) != 0) {
            trigger(event.type, event);
        }
    }

    bool EventManager::isKeyPressed(Uint8 key) {
        const Uint8 *keyState = SDL_GetKeyboardState(nullptr);
        return keyState[key] != 0u;
    }
}  // namespace AcsGameEngine