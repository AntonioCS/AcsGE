#pragma once


#include <vector>
#include <string>
#include <utility> //std::pair
#include <unordered_map>
#include <memory> //unique_ptr

#include <SDL2/SDL.h>

namespace AcsGameEngine
{
    class Renderer;
    class Sprite;
    class AssetManager;

}


namespace AcsGameEngine::Util {

    class Misc
    {
    public:
        static void imageToSprites(
            AssetManager &assetManager,
            const std::string &imagePath,
            const std::vector<std::pair<std::string, SDL_Rect>> &coords,
            std::unordered_map<std::string, std::unique_ptr<Sprite>> &destination);
    };
}
