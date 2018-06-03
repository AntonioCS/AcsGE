#include "EventManager.h"

#include <utility>

namespace AcsGameEngine {

    void EventManager::onMouseClick(eventFunc func) {
        attach(SDL_MOUSEBUTTONUP, std::move(func));
    }

    void EventManager::onKeyDown(eventFunc func) {
        attach(SDL_KEYDOWN, std::move(func));
    }

    void EventManager::onQuit(eventFunc func) {
        attach(SDL_QUIT, std::move(func));
    }

    void EventManager::onEvent(Uint32 eventName, eventFunc func) {
        attach(eventName, std::move(func));
    }

    void EventManager::processEvents() {
        while (SDL_PollEvent(&m_event) != 0) {
            trigger(m_event.type, m_event);
        }
    }

    bool EventManager::isKeyPressed(Uint8 key) {
        const Uint8 *keyState = SDL_GetKeyboardState(nullptr);
        return keyState[key] != 0u;
    }
}  // namespace AcsGameEngine