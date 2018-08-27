#include <SDL2/SDL_image.h>
#include <utility>
#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <utility> //std::pair
#include <algorithm> // std::min, std::max
#include <unordered_map>

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

void Renderer::DrawColor(const CList::Color& color)
{
    if (color != CList::_nocolor) {
        m_currentColor = color;
        DrawColor(color.r, color.g, color.b, color.a);
    }
}

void Renderer::DrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t alpha) const
{
    SDL_SetRenderDrawColor(getRawPointer(), r, g, b, alpha);
}

void Renderer::Clear(const Util::ColorList::Color& c)
{
    DrawColor(c);
    SDL_RenderClear(getRawPointer());
}

void Renderer::Present() const
{
    SDL_RenderPresent(getRawPointer());
}

void Renderer::DrawRect(const SDL_Rect rect, const CList::Color& c, bool fill)
{
    DrawColor(c);
    fill ? SDL_RenderFillRect(getRawPointer(), &rect) : SDL_RenderDrawRect(getRawPointer(), &rect);
}

void Renderer::DrawRect(const Sprite &sprite, const CList::Color & c, bool fill)
{
    DrawRect(sprite.getDestination(), c, fill);
}

SDL_Renderer* Renderer::getRawPointer() const
{
    return m_renderer.get();
}

const Window& Renderer::getWindow() const
{
    return m_window;
}

bool Renderer::hasColor() const noexcept
{
    return m_currentColor != CList::_nocolor;
}

Renderer::CList::Color Renderer::getColor() const noexcept
{
    return m_currentColor;
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

void Renderer::DrawLine(int x1, int y1, int x2, int y2, const CList::Color & c)
{
    DrawColor(c);
    SDL_RenderDrawLine(getRawPointer(), x1, y1, x2, y2);
}

void Renderer::DrawPoint(int x, int y, const CList::Color &c)
{
    DrawColor(c);
    SDL_RenderDrawPoint(getRawPointer(), x, y);
}

//https://gist.github.com/derofim/912cfc9161269336f722
//https://en.wikipedia.org/wiki/Midpoint_circle_algorithm#C_Example
void Renderer::DrawCircle(std::pair<int, int> center, int radius, const CList::Color & c, bool fill)
{
    auto[x0, y0] = center;
    std::vector<std::pair<int, int>> points;
    auto toRadians = [](int degree) -> double {
        return degree * (M_PI / 180);
    };

    auto createPoints = [](int x0, int y0, int radius, std::vector<std::pair<int, int>> &points) -> void {
        int x = radius - 1;
        int y = 0;
        int dx = 1;
        int dy = 1;
        int err = dx - (radius << 1);

        while (x >= y)
        {
            points.emplace_back(x0 + x, y0 + y);
            points.emplace_back(x0 + y, y0 + x);
            points.emplace_back(x0 - y, y0 + x);
            points.emplace_back(x0 - x, y0 + y);
            points.emplace_back(x0 - x, y0 - y);
            points.emplace_back(x0 - y, y0 - x);
            points.emplace_back(x0 + y, y0 - x);
            points.emplace_back(x0 + x, y0 - y);

            if (err <= 0)
            {
                y++;
                err += dy;
                dy += 2;
            }

            if (err > 0)
            {
                x--;
                dx += 2;
                err += dx - (radius << 1);
            }
        }
    };

    //auto deg = 0;
    /*
    while (deg < 360) {
        auto rad = toRadians(deg);
        auto x2 = x + (radius * std::cos(rad));
        auto y2 = y - (radius * std::sin(rad));

        deg++;
        */
        //std::cout << "x2: " << x2 << " y2: " << y2 << " Degrees: " << deg << '\n';
        /*
        if (deg > 1) {
            const auto &[last_x, last_y] = points.back();
            auto a = std::min(last_y, static_cast<int>(y2));
            auto b = std::max(last_y, static_cast<int>(y2));
            auto res = b - a;

            if (res > 1) {
                while (res) {
                    points.emplace_back(last_x, b - res--);
                }
            }
        }*/

      //  points.emplace_back(static_cast<int>(std::ceil(x2)), static_cast<int>(std::ceil(y2)));
    //}

    createPoints(x0, y0, radius, points);

    if (fill) {
        std::unordered_map<int, std::vector<int>> xPoints;

        for (const auto&[x2, y2] : points) {
            if (xPoints.count(y2)) {
                xPoints[y2].push_back(x2);
            }
            else {
                xPoints[y2] = std::vector<int>{ x2 };
            }
        }

        for (const auto &[y, values] : xPoints) {
            if (values.size() >= 2) {
                const auto [xSmall, xBig] = std::minmax_element(values.begin(), values.end());
                DrawLine(*xSmall, y, *xBig, y, CList::dark_blue);
            }
        }
    }

    for (const auto&[x2, y2] : points) {
        DrawPoint(x2, y2, c);
    }
}

Texture Renderer::make_texture(const std::string & path, const Util::ColorList::Color transparentColor)
{
    SDL_Surface *tmp = IMG_Load(path.c_str());

    if (tmp == nullptr) {
        throw std::string{ "Unable to load image: " } +path;
    }

    if (transparentColor != Util::ColorList::_nocolor) {
        SDL_SetColorKey(tmp, SDL_TRUE, SDL_MapRGB(tmp->format, transparentColor.r, transparentColor.g, transparentColor.b));
    }

	SDL_Texture *t = SDL_CreateTextureFromSurface(getRawPointer(), tmp);
	SDL_FreeSurface(tmp);

	return Texture{ t };
}

} // namespace AcsGameEngine
