#pragma once

#include <SDL2/SDL.h>
#include <memory>
#include <string>

namespace AcsGameEngine {

    class Window;
    class Texture;
    class Sprite;

    namespace Util {
        class Color;
    }

    using Util::Color;

    class Renderer {
    public:
        explicit Renderer(Window& window, int index = -1, Uint32 flags = SDL_RENDERER_ACCELERATED);
        Renderer(const Renderer& orig) = delete;
        Renderer(Renderer &&) = default;
        Renderer& operator=(const Renderer& other);
        Renderer& operator=(Renderer && other) noexcept;
        ~Renderer() = default;

        void drawColor(const Color&) const noexcept;
        void drawColor(const Color*) const noexcept;
        void drawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t alpha = 255) const noexcept;

        void clear(const Color &) const noexcept;
        void clear() const noexcept;

        void present() const noexcept;

        void drawRect(SDL_Rect, bool fill = false) const noexcept;
        void drawRect(const Sprite &, bool fill = false) const noexcept;
        void drawLine(int x1, int y1, int x2, int y2) const noexcept;
        void drawPoint(int x, int y) const noexcept;

        void drawSprite(const Sprite *) const noexcept;
        void drawSprite(const Sprite &) const noexcept;

        Texture makeTexture(const std::string & path) const;
        Texture makeTexture(const std::string & path, const Color &transparentColor) const;

        SDL_Renderer* getRawPointer() const noexcept;
        const Window& getWindow() const noexcept;

    private:
        std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;
        Window& m_window;
        SDL_Renderer* createRendererPointer(SDL_Window* w, int index, Uint32 flags) const noexcept;
    };
} //namespace AcsGameEngine
