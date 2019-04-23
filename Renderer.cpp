
#include "Renderer.h"

#include "Sprite.h"
#include "Sprite2.h"
#include "Texture.h"
#include "Window.h"
#include "Util/Color.h"
#include "Util/ColorList.h"
#include "Util/Shapes/Rectangle.h"
#include "Font.h"

#include <SDL2/SDL_image.h>
#include <algorithm>


namespace AcsGameEngine {
    using Util::Color;
    using Util::ColorList;

    Renderer::Renderer(Window& window, int index, Uint32 flags)
        : m_renderer(createRendererPointer(window.getRawPointer(), index, flags), SDL_DestroyRenderer)
        , m_window(window)
    {
        if (m_renderer == nullptr) {
            throw std::runtime_error{
                std::string{ "Unable to initialize renderer: " } +std::string{ SDL_GetError() }
            };
        }

        SDL_SetRenderDrawBlendMode(getRawPointer(), SDL_BLENDMODE_BLEND);
    }

    //https://wiki.libsdl.org/SDL_CreateRenderer
    SDL_Renderer* Renderer::createRendererPointer(SDL_Window* w, int index, Uint32 flags) const noexcept
    {
        return SDL_CreateRenderer(w, index, flags);
    }

    Renderer & Renderer::operator=(const Renderer & other)
    {
        if (&other != this) {
        }
        return *this;
    }

    Renderer & Renderer::operator=(Renderer && other) noexcept
    {
        if (&other != this) {
        }
        return *this;
    }

    void Renderer::drawColor(const Color& color) const noexcept
    {
        if (color != ColorList::_nocolor) {
            //m_currentColor = color;
            drawColor(color.r, color.g, color.b, color.a);
        }
    }

    void Renderer::drawColor(const Color *color) const noexcept
    {
        drawColor(*color);
    }

    void Renderer::drawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t alpha) const noexcept
    {
        SDL_SetRenderDrawColor(getRawPointer(), r, g, b, alpha);
    }

    void Renderer::clear(const Color &c) const noexcept
    {
        drawColor(c);
        clear();
    }
    void Renderer::clear() const noexcept
    {
        SDL_RenderClear(getRawPointer());
    }

    void Renderer::present() const noexcept
    {
        SDL_RenderPresent(getRawPointer());
    }

    void Renderer::drawRect(const SDL_Rect rect, bool fill) const noexcept
    {
        fill ? SDL_RenderFillRect(getRawPointer(), &rect) : SDL_RenderDrawRect(getRawPointer(), &rect);
    }

    void Renderer::drawRect(const Sprite &sprite, bool fill) const noexcept
    {
        drawRect(sprite.getDestination(), fill);
    }

    SDL_Renderer* Renderer::getRawPointer() const noexcept
    {
        return m_renderer.get();
    }

    const Window& Renderer::getWindow() const noexcept
    {
        return m_window;
    }

    void internalDrawSprite(SDL_Renderer *renderer, Sprite &sprite)
    {
        Texture *texture = sprite.getTexture();
        auto source = sprite.getSource();
        auto destination = sprite.getDestination();
        SDL_RenderCopyEx(
            renderer,
            texture->getRawPointer(),
            &source,
            &destination,
            160.0,
            //sprite.angle(),
            nullptr,//&(sprite.centerPoint()), @TODO - Fix this. If the angle > 0 then this messes up the whole thing unless it's null
            SDL_FLIP_NONE
            //sprite.flip()
        );
    }


    void Renderer::drawSprite(const Sprite *sprite) const noexcept
    {
        drawSprite(*sprite);
    }

    void AcsGameEngine::Renderer::drawSprite(const Sprite& sprite) const noexcept
    {
        Texture *texture = sprite.getTexture();
        auto source = sprite.getSource();
        auto destination = sprite.getDestination();
        //SDL_RenderCopy(getRawPointer(), texture.getRawPointer(), &(sprite.getSource()), &(sprite.getDestination()));
        SDL_RenderCopyEx(
            getRawPointer(),
            texture->getRawPointer(),
            &source,
            &destination,
            0,
            //sprite.angle(),
            nullptr,//&(sprite.centerPoint()), @TODO - Fix this. If the angle > 0 then this messes up the whole thing unless it's null
            SDL_FLIP_NONE
            //sprite.flip()
        );
    }

    void Renderer::drawSprite(const Sprite2* sprite, const SpriteFlipState state, SpriteCenterPoint centerPoint,
        double rotation, int alphaPercentage, const Util::Size scale) const noexcept
    {
        drawSprite(
            sprite, 
            sprite->getDestination(),
            state, centerPoint,
            rotation, alphaPercentage,scale
        );
    }

    void Renderer::drawSprite(
        const Sprite2* sprite, 
        const Util::Shapes::Rectangle& destination, 
        const SpriteFlipState flipState,
        SpriteCenterPoint centerPoint, 
        double rotation, 
        int alphaPercentage,
        const Util::Size scale) const noexcept
    {
        constexpr int alphaMax{ 255 };

        auto[spriteX, spriteY] = sprite->getPosition().getXYint();
        auto[spriteW, spriteH] = sprite->getSize().getWHint();
        SDL_Rect source = { spriteX, spriteY, spriteW, spriteH };

        auto scaledDest = destination.size * scale;

        auto[destX, destY] = destination.origin.getXYint();
        auto[destW, destH] = scaledDest.getWHint();
        SDL_Rect dest = { destX, destY, destW, destH };

        SDL_Point cPoint;

        switch (centerPoint) {
            case SpriteCenterPoint::TOP_LEFT:
                cPoint.x = 0;
                cPoint.y = 0;
            break;
            case SpriteCenterPoint::TOP_CENTER:
                cPoint.x = destW / 2;;
                cPoint.y = 0;
            break;
            case SpriteCenterPoint::TOP_RIGHT:
                cPoint.x = destW;
                cPoint.y = 0;
            break;
            case SpriteCenterPoint::MIDDLE_LEFT:
                cPoint.x = 0;
                cPoint.y = destH / 2;
            break;
            case SpriteCenterPoint::MIDDLE_CENTER:
                //a nullptr will be used

            break;
            case SpriteCenterPoint::MIDDLE_RIGHT:
                cPoint.x = destW / 2;
                cPoint.y = destH / 2;
            break;
            case SpriteCenterPoint::BOTTOM_LEFT:
                cPoint.x = 0;
                cPoint.y = destH;
            break;
            case SpriteCenterPoint::BOTTOM_CENTER:
                cPoint.x = destW / 2;
                cPoint.y = destH;
            break;
            case SpriteCenterPoint::BOTTOM_RIGHT:
                cPoint.x = destW;
                cPoint.y = destH;
            break;
        }
        SDL_RendererFlip fState = SDL_FLIP_NONE;

        switch (flipState) {
            case SpriteFlipState::Horizontal:
                fState = SDL_FLIP_HORIZONTAL;
                break;
            case SpriteFlipState::Vertical:
                fState = SDL_FLIP_VERTICAL;
                break;        
        }
        const auto texturePtr = sprite->getTexture()->getRawPointer();
        const auto alphaValue = alphaMax * (std::clamp(alphaPercentage, 0, 100) / 100);

        SDL_SetTextureAlphaMod(texturePtr, alphaValue);

        SDL_RenderCopyEx(
            getRawPointer(),
            texturePtr,
            &source,
            &dest,
            rotation,
            (centerPoint == SpriteCenterPoint::MIDDLE_CENTER  ? nullptr : &cPoint),
            fState
        );
    }    

    void Renderer::drawLine(int x1, int y1, int x2, int y2) const noexcept
    {
        SDL_RenderDrawLine(getRawPointer(), x1, y1, x2, y2);
    }

    void Renderer::drawPoint(int x, int y) const noexcept
    {
        SDL_RenderDrawPoint(getRawPointer(), x, y);
    }

    Texture Renderer::makeTexture(const std::string& path) const
    {
        return makeTexture(path, ColorList::_nocolor);
    }

    Texture Renderer::makeTexture(const std::string & path, const Color &transparentColor) const
    {
        SDL_Surface *tmpSurface = IMG_Load(path.c_str());

        if (tmpSurface == nullptr) {
            throw std::invalid_argument{ std::string{ "Unable to load image: "} +path };
        }

        if (transparentColor != ColorList::_nocolor) {
            SDL_SetColorKey(tmpSurface, SDL_TRUE, SDL_MapRGB(tmpSurface->format, transparentColor.r, transparentColor.g, transparentColor.b));
        }

        SDL_Texture *texture = SDL_CreateTextureFromSurface(getRawPointer(), tmpSurface);
        SDL_FreeSurface(tmpSurface);

        if (texture == nullptr) {
            throw std::invalid_argument{ "Unable to generate texture from surface" };
        }

        return Texture{ texture };
    }

    //http://headerphile.com/sdl2/sdl2-part-10-text-rendering/
    //http://headerphile.com/sdl2/sdl2-part-11-text-styling/
    //@todo code to generate texture has parts of it duplicated. Try to move to one function
    Texture Renderer::makeTexture(const Font& font, const std::string& text, const Color& color) const
    {
        SDL_Surface *tmpSurface = TTF_RenderText_Blended(
            font.getRawPointer(),
            text.c_str(),
            SDL_Color{ 
                static_cast<Uint8>(color.r), 
                static_cast<Uint8>(color.g), 
                static_cast<Uint8>(color.b), 
                static_cast<Uint8>(color.a) 
            }
        );

        if (tmpSurface == nullptr) {
            throw std::invalid_argument{ "Unable to generate surface from font" };
        }

        SDL_Texture *texture = SDL_CreateTextureFromSurface(getRawPointer(), tmpSurface);
        SDL_FreeSurface(tmpSurface);

        if (texture == nullptr) {
            throw std::invalid_argument{"Unable to generate texture from surface"};
        }

        return Texture{ texture };
    }
}
