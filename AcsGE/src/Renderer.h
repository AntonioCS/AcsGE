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

private:
    class TextureFactory {
    private:
        const Renderer &m_renderer;
        std::unordered_map<std::string, std::weak_ptr<Texture>> m_items;

    public:
        TextureFactory(const Renderer &r) : m_renderer(r) {

        }
        std::shared_ptr<Texture> getTexture(const std::string& path)
        {
            auto res = m_items.find(path);
            std::shared_ptr<Texture> item;
            auto func = [this, &item](const std::string& path) {
                SDL_Surface* tmp = IMG_Load(path.c_str());
                SDL_Texture* t = SDL_CreateTextureFromSurface(m_renderer.getRawPointer(), tmp);
                SDL_FreeSurface(tmp);

                item = std::make_shared<Texture>(t);
                m_items[path] = std::weak_ptr<Texture>(item);
            };

            if (res == m_items.end()) {
                func(path);
            }
            else {
                item = res->second.lock();
                if (item == nullptr) {
                    func(path);
                }
            }

            return item;
        }
    };    

public:
    explicit Renderer(const Window& window, int index = -1, Uint32 flags = SDL_RENDERER_ACCELERATED);
    Renderer(const Renderer& orig) = delete;
    Renderer(Renderer &&) = default;
    Renderer& operator=(const Renderer& other)
    {
        if (&other != this) {
            
        }
        return *this;
    }
    Renderer& operator=(Renderer && other)
    {
        if (&other != this) {
            
        }
        return *this;
    }
    
    void DrawColor(const Util::ColorList::Color& /*color*/, uint8_t alpha = 255) const;
    void DrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t alpha = 255) const;
    void Clear() const;
    void Clear(const Util::ColorList::Color& /*color*/) const;
    void Present() const;
    void DrawRect(SDL_Rect, const Util::ColorList::Color &c = Util::ColorList::_nocolor, bool fill = false) const;
    void DrawSprite(const Sprite &) const noexcept;

    std::shared_ptr<Texture> MakeTexture(const std::string &path) noexcept;
    Sprite MakeSprite(std::shared_ptr<Texture>) const noexcept;
    Sprite MakeSprite(const std::string &) noexcept;

    SDL_Renderer* getRawPointer() const;
    const Window& getWindow() const;
private:
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;
    const Window& m_window;
    TextureFactory m_tf;
    SDL_Renderer* createRendererPointer(SDL_Window* w, int index, Uint32 flags);
    
};
} //namespace AcsGameEngine

#endif // RENDERER_H