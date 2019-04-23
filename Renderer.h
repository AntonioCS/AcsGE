#pragma once

#include <SDL2/SDL_render.h>
#include <memory>
#include <string>
#include "Util/ColorList.h"
#include "Util/Vector2D.h"
#include "Util/Size.h"

namespace AcsGameEngine {
    class Window;
    class Texture;
    class Sprite;
    class Sprite2;
    class Font;
    class SpriteDrawData;

    namespace Util {
        namespace Shapes {
            class Rectangle;
        }

        class Color;
    }

    using Util::Color;

    class Renderer {
    public:
        enum class SpriteFlipState
        {
            None,
            Horizontal,
            Vertical
        };

        enum class SpriteCenterPoint
        {
            TOP_LEFT,
            TOP_CENTER,
            TOP_RIGHT,
            MIDDLE_LEFT,
            MIDDLE_CENTER,
            MIDDLE_RIGHT,
            BOTTOM_LEFT,
            BOTTOM_CENTER,
            BOTTOM_RIGHT
        };


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
        //void drawSprite(const SpriteDrawData &) const noexcept;
        void drawSprite(
            const Sprite2* sprite,            
            const SpriteFlipState state = SpriteFlipState::None,
            SpriteCenterPoint centerPoint = SpriteCenterPoint::MIDDLE_CENTER,
            double rotation = 0,
            int alphaPercentage = 100,
            const Util::Size scale = { 1,1 }
        ) const noexcept;
        void drawSprite(
            const Sprite2* sprite, 
            const Util::Shapes::Rectangle& destination,
            const SpriteFlipState state = SpriteFlipState::None, 
            SpriteCenterPoint centerPoint = SpriteCenterPoint::MIDDLE_CENTER, 
            double rotation = 0,
            int alphaPercentage =  100, 
            const Util::Size scale = { 1,1 }
        ) const noexcept;

        Texture makeTexture(const std::string & path) const;
        Texture makeTexture(const std::string & path, const Color &transparentColor) const;
        Texture makeTexture(const Font &font, const std::string &text, const Color &color) const;
        //Texture makeTexture(const Font &font, const std::string &text, const Color &color, const Color &bkgColor) const;

        SDL_Renderer* getRawPointer() const noexcept;
        const Window& getWindow() const noexcept;

    private:
        std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;
        Window& m_window;
        SDL_Renderer* createRendererPointer(SDL_Window* w, int index, Uint32 flags) const noexcept;
    };
} //namespace AcsGameEngine
