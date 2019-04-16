#include "Window.h"
#include <utility> //std::pair

namespace AcsGameEngine {
    Window::Window(const std::string &title, int x, int y, int w, int h, uint32_t flags)
        : m_window(createWindowPointer(title, x, y, w, h, flags), SDL_DestroyWindow)
    {
    }

    int Window::getX() const noexcept
    {
        const auto pos = getPosition();
        return pos.first;
    }

    int Window::getY() const noexcept
    {
        const auto pos = getPosition();
        return pos.second;
    }

    int Window::getWidth() const noexcept
    {
        const auto[w, h] = getSize();
        return w;
    }

    int Window::getHeight() const noexcept
    {
        const auto[w, h] = getSize();
        return h;
    }

    std::string Window::getTitle() const noexcept
    {
        return std::string{ SDL_GetWindowTitle(getRawPointer()) };
    }

    void Window::setTitle(const std::string& title) const noexcept
    {
        SDL_SetWindowTitle(getRawPointer(), title.c_str());
    }

    void Window::showWindow() const noexcept
    {
        SDL_ShowWindow(getRawPointer());
    }

    void Window::hideWindow() const noexcept
    {
        SDL_HideWindow(getRawPointer());
    }

    bool Window::isHidden() const noexcept
    {
        return isFlagSet(SDL_WINDOW_HIDDEN);
    }

    bool Window::isFlagSet(uint32_t flag) const noexcept
    {
        return ((SDL_GetWindowFlags(m_window.get()) & flag) == flag);
    }

    SDL_Window *Window::getRawPointer() const
    {
        return m_window.get();
    }

    std::pair<int, int> Window::getPosition() const noexcept
    {
        int x;
        int y;

        SDL_GetWindowPosition(getRawPointer(), &x, &y);
        return { x, y };
    }

    Util::Size Window::getSize() const noexcept
    {
        int w;
        int h;

        SDL_GetWindowSize(getRawPointer(), &w, &h);
        return { w, h };
    }

    Util::Vector2D Window::getCenter() const
    {
        const auto[w, h] = getSize();
        return { w/2.f, h/2.f};
    }

    SDL_Window *Window::createWindowPointer(const std::string& title, int x, int y, int w, int h, uint32_t flags)
    {
        return SDL_CreateWindow(title.c_str(), x, y, w, h, flags);
    }
}  // namespace AcsGameEngine