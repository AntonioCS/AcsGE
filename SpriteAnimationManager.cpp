#include "SpriteAnimationManager.h"

namespace AcsGameEngine {
    SpriteAnimationManager& SpriteAnimationManager::add(std::string name, SpriteAnimation2 animation)
    {
        m_animations.emplace(name, std::move(animation));
        setDefaultAnimation(name);

        return *this;
    }

    void SpriteAnimationManager::play()
    {
        play(m_defaultAnimation);
    }

    void SpriteAnimationManager::play(const std::string& name)
    {
        if (!(isPlaying() && m_currentAnimation == name)) {
            if (m_animations.find(name) != m_animations.end()) {
                if (m_playing) {
                    stop();
                }

                m_playing = true;
                m_animations[name].play();
                m_currentAnimation = name;
            }
            else {
                throw std::logic_error{ "Trying to load unknown animation" };
            }
        }
    }

    void SpriteAnimationManager::stop()
    {
        if (m_playing && !m_currentAnimation.empty()) {
            m_animations[m_currentAnimation].reset();
            m_playing = false;
        }
    }

    bool SpriteAnimationManager::update(std::chrono::milliseconds elapsed)
    {
        if (m_playing && !m_currentAnimation.empty()) {
            return m_animations[m_currentAnimation].update(elapsed);
        }

        return false;
    }

    AcsGameEngine::Sprite2* SpriteAnimationManager::current()
    {
        if (!m_currentAnimation.empty()) {
            return m_animations[m_currentAnimation].get();
        }
        else if (!m_defaultAnimation.empty()) {
            return m_animations[m_defaultAnimation].get();
        }

        return nullptr;
    }

    std::string* SpriteAnimationManager::currentAnimationName()
    {
        if (!m_currentAnimation.empty()) {
            return &m_currentAnimation;
        }

        return nullptr;
    }

    bool SpriteAnimationManager::isPlaying() const
    {
        return m_playing;
    }

    void SpriteAnimationManager::setDefaultAnimation(std::string name)
    {
        if (m_animations.find(name) != m_animations.end()) {
            m_defaultAnimation = name;
        }
        else{
            throw std::logic_error{ "Unknown animation" };
        }
    }
}