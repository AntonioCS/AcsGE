
#include "Texture.h"

namespace AcsGameEngine {
    Texture::Texture() : m_texturePtr(nullptr, SDL_DestroyTexture)
    {
    }

    Texture::Texture(SDL_Texture *texture) : m_texturePtr(texture, SDL_DestroyTexture)
    {
    }

    void Texture::loadFromFile(std::string path)
    {
        m_filePath = path;
    }

    void Texture::loadFromFile(std::string path, const Util::Color& transparentColor)
    {
    }

    bool Texture::hasTexture() const noexcept
    {
        return (getRawPointer() != nullptr);
    }

    std::string Texture::getFilePathToTexture() const noexcept
    {
        return m_filePath;
    }

    SDL_Texture * Texture::getRawPointer() const
    {
        return m_texturePtr.get();
    }

    Util::Size Texture::getSize() const
    {
        if (hasTexture()) {
            int w, h;
            SDL_QueryTexture(getRawPointer(), nullptr, nullptr, &w, &h);

            return { w, h };
        }

        throw std::logic_error{ "No texture has been set" };
    }
}
