#include "AssetManager.h"
#include "Renderer.h"
#include <stdexcept> //runtime_error
#include <algorithm> //std::for_each
#include "Sprite2.h"

namespace AcsGameEngine
{
    AssetManager::AssetManager(Renderer* r)
    {
        this->setRenderer(r);
    }

    bool AssetManager::hasTexture(const std::string& name) const
    {
        return m_textures.find(name) != m_textures.end();
    }

    Texture* AssetManager::makeTexture(const std::string& texturePath, Util::Color colorKey)
    {
        return makeTexture(texturePath, texturePath, colorKey);
    }

    AcsGameEngine::Texture* AssetManager::makeTexture(const std::string& name, const std::string& texturePath, Util::Color colorKey)
    {
        if (!hasTexture(name)) {
            m_textures.insert({name, getRenderer()->makeTexture(texturePath, colorKey)});
            return &m_textures[name];
        }

        return getTexture(name);
    }

    Texture* AssetManager::getTexture(const std::string& name)
    {
        if (hasTexture(name)) {
            return &m_textures[name];
        }

        return nullptr;
    }

    bool AssetManager::hasSprite(const std::string& name) const
    {
        return m_sprites.find(name) != m_sprites.end();
    }

    void AssetManager::makeSprites(const std::string& textureName, const std::vector<MultiData>& nameAndCoords)
    {

        auto texture = getTexture(textureName);

        std::for_each(
            nameAndCoords.begin(),
            nameAndCoords.end(),
            [&texture, this](const MultiData& data)
        {
            auto[name, vec, size] = data;

            if (!this->hasSprite(name)) {
                this->m_sprites.insert({ name, Sprite2(texture, vec, size) });
            }
            else {
                throw std::runtime_error{ "Sprite with name: " + name + " already exists" };
            }
        }
        );

    }

    Sprite2* AssetManager::getSprite(const std::string& name)
    {
        if (hasSprite(name)) {
            return &m_sprites[name];
        }

        return nullptr;
    }

    Font *AssetManager::loadFont(const std::string &name, const std::string& path, int size)
    {
        const auto font = TTF_OpenFont(path.c_str(), size);

        if (font == nullptr) {
            throw std::runtime_error{"Unable to load font from path: "  + path};
        }

        m_fonts[name].emplace(size, Font(font));
        return &(m_fonts[name][size]);    
    }

    Font *AssetManager::loadFont(const std::string& path, int size)
    {
        return loadFont(path, path, size);
    }

    Font* AssetManager::getFont(const std::string& name, int size)
    {
        /*auto res = m_fonts.find(name);
        
        if (res != m_fonts.end) {
            auto res2 = res->second.find(size);

            if (res2 != res->second.end()) {
                return &(res2->second);
            }
        }*/

        return nullptr;
    }

    void AssetManager::loadFontMap(
        const std::string& name, const std::string& pathToFontSprite,
        const std::string& pathToFontMap, Util::Color colorKey)
    {
        makeTexture(name, pathToFontSprite, colorKey);
        m_fontAtlas.emplace(name, FontAtlas{pathToFontMap});
    }

    bool AssetManager::hasFontMap(const std::string& name)
    {
        return m_fontAtlas.find(name) != m_fontAtlas.end();
    }

    std::optional<std::pair<Texture*, FontAtlas>> AssetManager::getFontMap(const std::string& name)
    {
        if (hasTexture(name) && hasFontMap(name)) {
            return std::make_pair(getTexture(name), m_fontAtlas[name]);
        }

        return {};
    }
}
