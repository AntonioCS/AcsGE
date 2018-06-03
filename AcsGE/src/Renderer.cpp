#include <SDL2/SDL_image.h>

#include "Renderer.h"
#include "Sprite.h"
#include "Texture.h"
#include "Window.h"


namespace AcsGameEngine {


Renderer::Renderer(const Window& window, int index, Uint32 flags)
    : m_renderer(createRendererPointer(window.getRawPointer(), index, flags), SDL_DestroyRenderer)
    , m_window(window)
    , m_tf(*this)
{

    if (m_renderer == nullptr) {
        throw std::runtime_error(std::string{ "Unable to initialize renderer: " }
            + std::string{ SDL_GetError() });
    }
}

SDL_Renderer* Renderer::createRendererPointer(SDL_Window* w, int index, Uint32 flags)
{
    return SDL_CreateRenderer(w, index, flags);
}

void Renderer::DrawColor(const Util::ColorList::Color& color, uint8_t alpha) const
{
    DrawColor(color.r, color.g, color.b, alpha);
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
    auto texture = sprite.getTexture();
    SDL_RenderCopy(getRawPointer(), texture->getRawPointer(), &(sprite.getSource()), &(sprite.getDestination()));
}

std::shared_ptr<Texture> Renderer::MakeTexture(const std::string& path) noexcept
{
    return m_tf.getTexture(path);
}

Sprite Renderer::MakeSprite(std::shared_ptr<Texture> t) const noexcept
{
    return { t };
}

Sprite Renderer::MakeSprite(const std::string& path) noexcept
{
    return MakeSprite(MakeTexture(path));
}

} // namespace AcsGameEngine