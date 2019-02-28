#pragma once

#include <SDL2/SDL.h>
#include <unordered_map>

namespace AcsGameEngine {

    class KeyboardManager
    {
    public:
        enum class Keys
        {
            ARROW_KEY_UP,
            ARROW_KEY_DOWN,
            ARROW_KEY_LEFT,
            ARROW_KEY_RIGHT
        };

        KeyboardManager(KeyboardManager const &) = delete;
        KeyboardManager(KeyboardManager &&) = delete;        

        void operator=(KeyboardManager const &) = delete;
        void operator=(KeyboardManager &&) = delete;

        ~KeyboardManager() = default;


        static KeyboardManager& getInstance();

        void onKeyDown(SDL_Event& e);

        void onKeyUp(SDL_Event& e);

        bool isPressed(Keys k) const;

    private:
        KeyboardManager() = default;

        std::unordered_map<Keys, bool> m_keys;
        std::unordered_map<SDL_Keycode, Keys> m_keysMappings{
            {SDLK_UP, Keys::ARROW_KEY_UP},
            {SDLK_DOWN, Keys::ARROW_KEY_DOWN},
            {SDLK_LEFT, Keys::ARROW_KEY_LEFT},
            {SDLK_RIGHT, Keys::ARROW_KEY_RIGHT}
        };

        bool hasKey(SDL_Keycode k) const noexcept;

        void setKeyState(SDL_Keycode sdlKey, bool state) noexcept;
    };
}