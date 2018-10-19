#include "Renderer.h"

#include <SDL2/SDL_image.h>

#include "Sprite.h"
#include "Texture.h"
#include "Window.h"
#include "Util/Color.h"
#include "Util/ColorList.h"


namespace AcsGameEngine {

    using Util::Color;
    using Util::ColorList;

    Renderer::Renderer(Window& window, int index, Uint32 flags)
        : m_renderer(createRendererPointer(window.getRawPointer(), index, flags), SDL_DestroyRenderer)
        , m_window(window)
    {

        if (m_renderer == nullptr) {
            throw std::runtime_error(std::string{ "Unable to initialize renderer: " }
            +std::string{ SDL_GetError() });
        }

        SDL_SetRenderDrawBlendMode(getRawPointer(), SDL_BLENDMODE_BLEND);
    }

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

    void Renderer::DrawColor(const Color& color) const noexcept
    {
        if (color != ColorList::_nocolor) {
            //m_currentColor = color;
            DrawColor(color.r, color.g, color.b, color.a);
        }
    }

    void Renderer::DrawColor(const Color *color) const noexcept
    {
        DrawColor(*color);
    }

    void Renderer::DrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t alpha) const noexcept
    {
        SDL_SetRenderDrawColor(getRawPointer(), r, g, b, alpha);
    }

    void Renderer::Clear(const Color &c) const noexcept
    {
        DrawColor(c);
        Clear();
    }
    void Renderer::Clear() const noexcept
    {
        SDL_RenderClear(getRawPointer());
    }

    void Renderer::Present() const noexcept
    {
        SDL_RenderPresent(getRawPointer());
    }

    void Renderer::DrawRect(const SDL_Rect rect, bool fill) const noexcept
    {
        fill ? SDL_RenderFillRect(getRawPointer(), &rect) : SDL_RenderDrawRect(getRawPointer(), &rect);
    }

    void Renderer::DrawRect(const Sprite &sprite, bool fill) const noexcept
    {
        DrawRect(sprite.getDestination(), fill);
    }

    SDL_Renderer* Renderer::getRawPointer() const noexcept
    {
        return m_renderer.get();
    }

    const Window& Renderer::getWindow() const noexcept
    {
        return m_window;
    }

    void AcsGameEngine::Renderer::DrawSprite(const Sprite& sprite) const noexcept
    {
        const Texture &texture = sprite.getTexture();
        //SDL_RenderCopy(getRawPointer(), texture.getRawPointer(), &(sprite.getSource()), &(sprite.getDestination()));
        SDL_RenderCopyEx(
            getRawPointer(),
            texture.getRawPointer(),
            &(sprite.getSource()),
            &(sprite.getDestination()),
            sprite.angle(),
            nullptr,//&(sprite.centerPoint()), @TODO - Fix this. If the angle > 0 then this messes up the whole thing unless it's null
            sprite.flip()
        );
    }

    void Renderer::DrawLine(int x1, int y1, int x2, int y2) const noexcept
    {
        SDL_RenderDrawLine(getRawPointer(), x1, y1, x2, y2);
    }

    void Renderer::DrawPoint(int x, int y) const noexcept
    {
        SDL_RenderDrawPoint(getRawPointer(), x, y);
    }

    Texture Renderer::make_texture(const std::string& path) const
    {
        return make_texture(path, ColorList::_nocolor);
    }

    Texture Renderer::make_texture(const std::string & path, const Color &transparentColor) const
    {
        SDL_Surface *tmp = IMG_Load(path.c_str());

        if (tmp == nullptr) {
            throw std::string{ "Unable to load image: " } +path;
        }

        if (transparentColor != ColorList::_nocolor) {
            SDL_SetColorKey(tmp, SDL_TRUE, SDL_MapRGB(tmp->format, transparentColor.r, transparentColor.g, transparentColor.b));
        }

        SDL_Texture *t = SDL_CreateTextureFromSurface(getRawPointer(), tmp);
        SDL_FreeSurface(tmp);

        return Texture{ t };
    }

} // namespace AcsGameEngine
