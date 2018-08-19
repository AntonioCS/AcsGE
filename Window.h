#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <memory>
#include <stdexcept>
#include <string>

namespace AcsGameEngine {
    //https://wiki.libsdl.org/SDL_CreateWindow

    class Window {
    public:
        explicit Window(std::string title = "SDL2 Window", int x = SDL_WINDOWPOS_CENTERED, int y = SDL_WINDOWPOS_CENTERED, int w = 800, int h = 600, uint32_t flags = SDL_WINDOW_OPENGL);

        Window(const Window &orig) = delete;

        int getX() const noexcept;

        int getY() const noexcept;

        std::pair<int, int> getPosition() const noexcept;

        std::pair<int, int> getSize() const noexcept;

        int getWidth() const noexcept;

        int getHeight() const noexcept;

        inline std::string getTitle() const noexcept;

        void setTitle(const std::string& title);

        SDL_Window *getRawPointer() const;
    private:        
        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window;        


/*
        void applyNewPosition() const noexcept {
            if (m_window != nullptr) {
                SDL_SetWindowPosition(m_window, m_x, m_y);
            }
        }

        void applyNewSize() const noexcept {
            if (m_window != nullptr) {
                SDL_SetWindowSize(m_window, m_w, m_h);
            }
        }
*/
        SDL_Window *createWindowPointer(const std::string& title, int x, int y, int w, int h, uint32_t flags);
    };
}  // namespace AcsGameEngine
#endif // WINDOW_H

