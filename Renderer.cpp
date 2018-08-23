#include <SDL2/SDL_image.h>
#include <utility>
#include <iostream>

#include "Renderer.h"
#include "Sprite.h"
#include "Texture.h"
#include "Window.h"


namespace AcsGameEngine {


Renderer::Renderer(const Window& window, int index, Uint32 flags)
    : m_renderer(createRendererPointer(window.getRawPointer(), index, flags), SDL_DestroyRenderer)
    , m_window(window)
{

    if (m_renderer == nullptr) {
        throw std::runtime_error(std::string{ "Unable to initialize renderer: " }
            + std::string{ SDL_GetError() });
    }

	SDL_SetRenderDrawBlendMode(getRawPointer(), SDL_BLENDMODE_BLEND);
}

SDL_Renderer* Renderer::createRendererPointer(SDL_Window* w, int index, Uint32 flags)
{
    return SDL_CreateRenderer(w, index, flags);
}

Renderer & Renderer::operator=(const Renderer & other)
{
	if (&other != this) {

	}
	return *this;
}

Renderer & Renderer::operator=(Renderer && other)
{
	if (&other != this) {

	}
	return *this;
}

void Renderer::DrawColor(const Util::ColorList::Color& color) const
{
    DrawColor(color.r, color.g, color.b, color.a);
}

void Renderer::DrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t alpha) const
{
    SDL_SetRenderDrawColor(getRawPointer(), r, g, b, alpha);
}

void Renderer::Clear(const Util::ColorList::Color& color) const
{
    DrawColor(color);
    Clear();
}

void Renderer::Clear() const
{
    SDL_RenderClear(getRawPointer());
}

void Renderer::Present() const
{
    SDL_RenderPresent(getRawPointer());
}

void Renderer::DrawRect(const SDL_Rect rect, const Util::ColorList::Color& c, bool fill) const
{
    if (c != Util::ColorList::_nocolor) {
        DrawColor(c);
    }

    fill ? SDL_RenderFillRect(getRawPointer(), &rect) : SDL_RenderDrawRect(getRawPointer(), &rect);
}

SDL_Renderer* Renderer::getRawPointer() const
{
    return m_renderer.get();
}

const Window& Renderer::getWindow() const
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

Texture Renderer::make_texture(const std::string & path)
{	
	SDL_Surface *tmp = IMG_Load(path.c_str());

    if (tmp == nullptr) {
        throw std::string{ "Unable to load image: " } +path;
    }

	SDL_Texture *t = SDL_CreateTextureFromSurface(getRawPointer(), tmp);
	SDL_FreeSurface(tmp);

	return Texture{ t };
}

} // namespace AcsGameEngine
