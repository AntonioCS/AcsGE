#include "AssetManager.h"
#include "Renderer.h"
#include <stdexcept> //runtime_error
#include <algorithm> //std::for_each

namespace AcsGameEngine {

    bool AssetManager::hasTexture(const std::string& name) const
    {
        return m_textures.find(name) != m_textures.end();
    }

    Texture* AssetManager::makeTexture(const std::string& texturePath)
    {
        return makeTexture(texturePath, texturePath);
    }

    AcsGameEngine::Texture* AssetManager::makeTexture(const std::string &name, const std::string& texturePath)
    {
        if (!hasTexture(name)) {
            m_textures.insert({ name,  getRenderer()->makeTexture(texturePath) });
            return &m_textures[name];
        }
        
        throw std::exception("Texture name exists");
    }

    Texture* AssetManager::getTexture(const std::string& name)
    {
        if (hasTexture(name))
        {
            return &m_textures[name];
        }

        return nullptr;
    }

    bool AssetManager::hasSprite(const std::string& name) const
    {
        return m_sprites.find(name) != m_sprites.end();
    }

    void AssetManager::makeSprites(
        const std::string& textureName,
        const std::vector<std::pair<std::string, SDL_Rect>>& nameAndCoords
    )
    {
        auto texture = getTexture(textureName);

        std::for_each(
            nameAndCoords.begin(),
            nameAndCoords.end(),
            [&texture, this](const std::pair<std::string, SDL_Rect> &pair)
            {
                auto[name, coords] = pair;

                if (!this->hasSprite(name)) {
                    this->m_sprites.insert({ pair.first, Sprite{*texture, coords} });
                }
                else {
                    throw std::runtime_error{
                        std::string{ "Sprite with name: " } + name + std::string{" already exists"}
                    };
                }
            }
        );
    
    }
}
