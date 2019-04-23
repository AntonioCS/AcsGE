#pragma once

#include <unordered_map>
#include <string>
#include <optional>

#include "Uses/UsesRenderer.h"
#include "Texture.h"
#include "Sprite.h"
#include "Sprite2.h"
#include "Font.h"
#include "Util/Size.h"
#include "Util/Vector2D.h"
#include "Util/Color.h"
#include "Util/ColorList.h"
#include "FontAtlas.h"


namespace AcsGameEngine {

    class Renderer;

    class AssetManager : public Uses::UsesRenderer
    {
    public:
        using Size = AcsGameEngine::Util::Size;
        using Vector2D = AcsGameEngine::Util::Vector2D;
        using MultiData = std::tuple<std::string, Vector2D, Size>;        
    public:
        AssetManager() = default;
        AssetManager(Renderer *r);

        ~AssetManager() = default;

        bool hasTexture(const std::string &name) const;
        Texture *makeTexture(const std::string &texturePath, Util::Color colorKey = Util::ColorList::_nocolor);
        Texture *makeTexture(const std::string &name, const std::string &texturePath, Util::Color colorKey = Util::ColorList::_nocolor);
        Texture *getTexture(const std::string &name);

        bool hasSprite(const std::string &name) const;        
        void makeSprites(const std::string &textureName, const std::vector<MultiData>& nameAndCoords);
        Sprite2 *getSprite(const std::string &name);

        Font *loadFont(const std::string &name, const std::string &path, int size);
        Font *loadFont(const std::string &path, int size);
        Font *getFont(const std::string &name, int size);
        Font *getFont(const std::string &name);

        void loadFontMap(const std::string &name, const std::string &pathToFontSprite, const std::string &pathToFontMap, Util::Color colorKey = Util::ColorList::_nocolor);
        bool hasFontMap(const std::string &name);
        std::optional<std::pair<Texture*, FontAtlas>> getFontMap(const std::string &name);

    private:
        std::unordered_map<std::string, Texture> m_textures;
        std::unordered_map<std::string, Sprite2> m_sprites;

        //<font name + size, Font>>
        //std::unordered_map<std::string, Font> m_fonts;
        std::unordered_map<std::string, std::unordered_map<int,Font>> m_fonts;

        std::unordered_map<std::string, FontAtlas> m_fontAtlas;
    };
}
