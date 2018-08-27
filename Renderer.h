#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include <string>
#include <unordered_map>

#include "Util/ColorList.h"

namespace AcsGameEngine {
    class Window;
    class Texture;
    class Sprite;

    class Renderer {
        using CList = Util::ColorList;

    public:
        explicit Renderer(const Window& window, int index = -1, Uint32 flags = SDL_RENDERER_ACCELERATED);
        Renderer(const Renderer& orig) = delete;
        Renderer(Renderer &&) = default;
        Renderer& operator=(const Renderer& other);
        Renderer& operator=(Renderer && other);

        void DrawColor(const Util::ColorList::Color&);
        void DrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t alpha = 255) const;
        void Clear(const CList::Color& c = CList::_nocolor);
        void Present() const;
        void DrawRect(SDL_Rect, const CList::Color &c = CList::_nocolor, bool fill = false);
        void DrawRect(const Sprite &Sprite, const CList::Color &c = CList::_nocolor, bool fill = false);
        void DrawSprite(const Sprite &) const noexcept;
        void DrawLine(int x1, int y1, int x2, int y2, const CList::Color &c = CList::_nocolor);
        void DrawPoint(int x, int y, const CList::Color &c = CList::_nocolor);
        void DrawCircle(std::pair<int, int> center, int radius, const CList::Color &c = CList::_nocolor, bool fill = false);

        Texture make_texture(const std::string & path, const Util::ColorList::Color transparentColor = CList::_nocolor);

        SDL_Renderer* getRawPointer() const;
        const Window& getWindow() const;

        bool hasColor() const noexcept;

        CList::Color getColor() const noexcept;

    private:
        std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;
        const Window& m_window;
        SDL_Renderer* createRendererPointer(SDL_Window* w, int index, Uint32 flags);

        CList::Color m_currentColor = CList::_nocolor;
    };
} //namespace AcsGameEngine
