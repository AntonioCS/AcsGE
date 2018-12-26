#include "Misc.h"
#include <algorithm> //std::for_each
#include "../Texture.h"
#include "../Renderer.h"
#include "../Sprite.h"
#include "../AssetManager.h"

namespace AcsGameEngine::Util {
    void Misc::imageToSprites(        
        AssetManager &assetManager,
        const std::string& imagePath,
        const std::vector<std::pair<std::string, SDL_Rect>>& coords,
        std::unordered_map<std::string, std::unique_ptr<Sprite>>& destination)
    {
        auto texture = assetManager.makeTexture(imagePath);                

        std::for_each(
            coords.begin(),
            coords.end(),
            [&texture, &destination](const std::pair<std::string, SDL_Rect> &pair)
            {
                destination[pair.first] = std::make_unique<AcsGameEngine::Sprite>(*texture, pair.second);
            }
        );
    }
}
