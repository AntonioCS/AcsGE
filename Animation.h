#pragma once

#include <SDL2/SDL.h>

#include <vector>
#include <string>
#include <utility> // std::pair

#include "Texture.h"
#include "Sprite.h"
#include "Util/Timer.h"

namespace AcsGameEngine {
    using namespace Util;
    class Animation
    {
        std::vector<std::pair<Sprite, std::chrono::milliseconds>> m_frames;
        const std::string m_name;
        const Texture &m_texture;

        std::chrono::milliseconds m_duration;
        unsigned int m_position{ 0 };
        bool m_running{ false };

        Timer m_timer;

        void applyToFrames(std::chrono::milliseconds);
    public:
        Animation(
            const std::string name,
            const Texture &texture
        );

        Animation(
            const std::string name,
            const Texture &texture,
            SDL_Rect start,
            unsigned totalFrames,
            SDL_Rect moveBy,
            std::chrono::milliseconds duration
        );

        ~Animation() = default;

        size_t totalFrames() const noexcept;

        void add(SDL_Rect, std::chrono::milliseconds);

        void play();
        void stop();
        Sprite &get();

        Sprite & get(int position);

        void delayBy(std::chrono::milliseconds);
        void speedUpBy(std::chrono::milliseconds);
    };
}