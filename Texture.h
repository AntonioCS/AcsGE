#pragma once

#include <SDL2/SDL_render.h>
#include <memory>
#include <string>
#include "Util/Size.h"
#include "Util/Color.h"

namespace AcsGameEngine {
    
    class Texture {
    public:
        Texture();
        Texture(SDL_Texture*);

        void setTexture(SDL_Texture*);
        void loadFromFile(std::string path);
        void loadFromFile(std::string path, const Util::Color &transparentColor);
        bool hasTexture() const noexcept;
        std::string getFilePathToTexture() const noexcept;

        SDL_Texture* getRawPointer() const;
        Util::Size getSize() const;        
    private:
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> m_texturePtr;
        std::string m_filePath{};
        Util::Color transparentColor;
    };
} // namespace AcsGameEngine
