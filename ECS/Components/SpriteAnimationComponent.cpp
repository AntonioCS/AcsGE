
#include "SpriteAnimationComponent.h"

namespace AcsGameEngine::ECS {


    SpriteAnimationComponent& SpriteAnimationComponent::add(std::string name, SpriteAnimation2 animation)
    {
        m_animations.emplace(name, std::move(animation));
        setDefaultAnimation(name);

        return *this;
    }

    void SpriteAnimationComponent::play()
    {
        play(m_defaultAnimation);
    }

    void SpriteAnimationComponent::play(const std::string& name)
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
                throw std::logic_error{"Trying to load unknown animation"};
            }
        }
    }

    void SpriteAnimationComponent::stop()
    {
        if (m_playing && !m_currentAnimation.empty()){
            m_animations[m_currentAnimation].reset();
            m_playing = false;
        }
    }

    void SpriteAnimationComponent::update(std::chrono::milliseconds elapsed)
    {
        if (m_playing && !m_currentAnimation.empty())
        {
            if (m_animations[m_currentAnimation].update(elapsed))
            {
                /*
                if (this->parentEntity->hasComponent<DimensionComponent>())
                {
                    auto[x, y, w, h] = m_animations[m_currentAnimation].get()->getDestination();
                    this->parentEntity->getComponent<DimensionComponent>().update(w, h);

                    std::cout << "Changing to: " << w << " --- " << h << '\n';
                }*/
            }
        }
    }

    AcsGameEngine::Sprite2* SpriteAnimationComponent::current()
    {
        if (!m_currentAnimation.empty())
        {
            return m_animations[m_currentAnimation].get();
        }
        else if (!m_defaultAnimation.empty())
        {
            return m_animations[m_defaultAnimation].get();
        }

        return nullptr;
    }

    std::string* SpriteAnimationComponent::currentAnimationName()
    {
        if (!m_currentAnimation.empty())
        {
            return &m_currentAnimation;
        }

        return nullptr;
    }

    bool SpriteAnimationComponent::isPlaying() const
    {
        return m_playing;
    }

    void SpriteAnimationComponent::setDefaultAnimation(std::string name)
    {
        if (m_animations.find(name) != m_animations.end())
        {
            m_defaultAnimation = name;
        }
        else
        {
            throw std::logic_error{"Unknown animation"};
        }
    }
}
