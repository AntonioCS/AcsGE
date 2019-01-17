#pragma once

#include <unordered_map>
#include <string>

#include "Uses/UsesRenderer.h"
#include "Texture.h"
#include "Sprite.h"

namespace AcsGameEngine  {
    class Renderer;    

    class AssetManager : public Uses::UsesRenderer
    {
    public:
        AssetManager() = default;
        AssetManager(Renderer *r);

        bool hasTexture(const std::string &name) const;
        Texture *makeTexture(const std::string &texturePath);
        Texture *makeTexture(const std::string &name, const std::string &texturePath);
        Texture *getTexture(const std::string &texturePath);

        bool hasSprite(const std::string &name) const;
        void makeSprites(const std::string &textureName, const std::vector<std::pair<std::string, SDL_Rect>>& nameAndCoords);
        Sprite *getSprite(const std::string &name);

    private:
        std::unordered_map<std::string, Texture> m_textures;
        std::unordered_map<std::string, Sprite> m_sprites;
    };
}
