﻿#pragma once

#include <unordered_map>
#include <string>
#include "SpriteAnimation2.h"

namespace AcsGameEngine {
    class SpriteAnimationManager
    {
        public:
            SpriteAnimationManager() = default;

            SpriteAnimationManager& add(std::string name, SpriteAnimation2 animation);

            void play();
            void play(const std::string& name);

            void stop();

            bool update(std::chrono::milliseconds elapsed);

            AcsGameEngine::Sprite2* current();

            std::string* currentAnimationName();

            bool isPlaying() const;

            void setDefaultAnimation(std::string name);
        private:
            std::unordered_map<std::string, SpriteAnimation2> m_animations;
            bool m_playing{ false };
            std::string m_currentAnimation;
            std::string m_defaultAnimation;
        };
}
