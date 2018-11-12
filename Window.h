#pragma once

#include <SDL2/SDL.h>
#include <memory>
#include <stdexcept>
#include <string>

namespace AcsGameEngine {
    //https://wiki.libsdl.org/SDL_CreateWindow
    class Window {
        struct WindowDefaults
        {
            inline static const std::string title{ "SDL2 Window" };
            inline static const int x{ SDL_WINDOWPOS_CENTERED };
            inline static const int y{ SDL_WINDOWPOS_CENTERED };
            inline static const int w{ 800 };
            inline static const int h{ 600 };
            inline static const uint32_t flags{ SDL_WINDOW_OPENGL | SDL_WINDOW_HIDDEN };
        };
    public:
        static constexpr int WINDOW_CENTERED = SDL_WINDOWPOS_CENTERED;

        explicit Window(
            const std::string &title = WindowDefaults::title,
            int x = WindowDefaults::x,
            int y = WindowDefaults::y,
            int w = WindowDefaults::w,
            int h = WindowDefaults::h,
            uint32_t flags = WindowDefaults::flags
        );

        ~Window() = default;
        Window(const Window &orig) = delete;
        Window(Window &&orig) = delete;

        int getX() const noexcept;
        int getY() const noexcept;

        std::pair<int, int> getPosition() const noexcept;
        std::pair<int, int> getSize() const noexcept;

        int getWidth() const noexcept;
        int getHeight() const noexcept;

        inline std::string getTitle() const noexcept;

        void setTitle(const std::string& title) const noexcept;

        void showWindow() const noexcept;
        void hideWindow() const noexcept;
        bool isHidden() const noexcept;

        SDL_Window *getRawPointer() const;
    private:
        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window;
        SDL_Window *createWindowPointer(const std::string& title, int x, int y, int w, int h, uint32_t flags);
        bool isFlagSet(uint32_t) const noexcept;
    };
}  // namespace AcsGameEngine
