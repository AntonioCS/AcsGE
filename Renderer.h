#ifndef RENDERER_H
#define RENDERER_H

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
public:
    explicit Renderer(const Window& window, int index = -1, Uint32 flags = SDL_RENDERER_ACCELERATED);
    Renderer(const Renderer& orig) = delete;
    Renderer(Renderer &&) = default;
	Renderer& operator=(const Renderer& other);
	Renderer& operator=(Renderer && other);

    void DrawColor(const Util::ColorList::Color& /*color*/, uint8_t alpha = 255) const;
    void DrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t alpha = 255) const;
    void Clear() const;
    void Clear(const Util::ColorList::Color& /*color*/) const;
    void Present() const;
    void DrawRect(SDL_Rect, const Util::ColorList::Color &c = Util::ColorList::_nocolor, bool fill = false) const;
    void DrawSprite(const Sprite &) const noexcept;

	Texture make_texture(const std::string & path);

    SDL_Renderer* getRawPointer() const;
    const Window& getWindow() const;
private:
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;
    const Window& m_window;
    SDL_Renderer* createRendererPointer(SDL_Window* w, int index, Uint32 flags);

};
} //namespace AcsGameEngine

#endif // RENDERER_H
