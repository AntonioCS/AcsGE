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
        std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;
        const Window& m_window;
        SDL_Renderer* createRendererPointer(SDL_Window* w, int index, Uint32 flags) const noexcept;

    public:
        explicit Renderer(const Window& window, int index = -1, Uint32 flags = SDL_RENDERER_ACCELERATED);
        Renderer(const Renderer& orig) = delete;
        Renderer(Renderer &&) = default;
        Renderer& operator=(const Renderer& other);
        Renderer& operator=(Renderer && other) noexcept;

        void DrawColor(const Color&) const noexcept;
        void DrawColor(const Color*) const noexcept;
        void DrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t alpha = 255) const noexcept;

        void Clear(const Color &) const noexcept;
        void Clear() const noexcept;
        void Present() const noexcept;

        void DrawRect(SDL_Rect, bool fill = false) const noexcept;
        void DrawRect(const Sprite &, bool fill = false) const noexcept;
        void DrawLine(int x1, int y1, int x2, int y2) const noexcept;
        void DrawPoint(int x, int y) const noexcept;

        void DrawSprite(const Sprite &) const noexcept;

        Texture make_texture(const std::string & path, const Color &transparentColor) const;

        SDL_Renderer* getRawPointer() const noexcept;
        const Window& getWindow() const noexcept;
    };
} //namespace AcsGameEngine
