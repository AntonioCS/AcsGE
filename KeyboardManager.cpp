#include "KeyboardManager.h"

namespace AcsGameEngine {

    KeyboardManager& AcsGameEngine::KeyboardManager::getInstance()
    {
        static KeyboardManager km;
        return km;
    }

    void KeyboardManager::onKeyDown(SDL_Event& e)
    {
        const auto key = e.key.keysym.sym;
        setKeyState(key, true);
    }

    void KeyboardManager::onKeyUp(SDL_Event& e)
    {
        const auto key = e.key.keysym.sym;
        setKeyState(key, false);
    }

    bool KeyboardManager::isPressed(Keys k) const
    {
        const auto k2 = m_keys.find(k);

        if (k2 != m_keys.end()) {
            return k2->second;
        }

        return false;
    }

    bool KeyboardManager::hasKey(SDL_Keycode k) const noexcept
    {
        return m_keysMappings.find(k) != m_keysMappings.end();
    }

    void KeyboardManager::setKeyState(SDL_Keycode sdlKey, bool state) noexcept
    {
        if (hasKey(sdlKey)) {
            m_keys[m_keysMappings[sdlKey]] = state;
        }
    }
}
