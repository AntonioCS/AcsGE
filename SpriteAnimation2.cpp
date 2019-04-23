#include "SpriteAnimation2.h"


using namespace std::chrono_literals;

namespace AcsGameEngine {

    SpriteAnimation2& SpriteAnimation2::addFrame(Sprite2* s, std::chrono::milliseconds delay)
    {
        m_frames.emplace_back(s, delay);
        return *this;
    }

    void SpriteAnimation2::play()
    {
        m_elapsed = 0ms;
        m_position = 0;
        m_total = m_frames.size();
    }

    bool SpriteAnimation2::update(std::chrono::milliseconds timeStep)
    {
        m_elapsed += timeStep;

        if (m_elapsed > m_frames.at(m_position).delay) {
            updatePosition();

            m_elapsed = 0ms;

            return true;
        }

        return false;
    }

    Sprite2* SpriteAnimation2::get()
    {
        if (m_reverse) {
            if (m_position < 0) {
                m_position = (m_loop ? m_total - 1 : 0);
            }
        }
        else {
            if (m_position >= m_total) {
                m_position = (m_loop ? 0 : m_total - 1);
            }
        }

        return m_frames[m_position].sprite;
    }

    void SpriteAnimation2::reset()
    {
        m_position = (m_reverse ? m_total - 1 : 0);
    }

    void SpriteAnimation2::reverse()
    {
        m_reverse = !m_reverse;
    }

    void SpriteAnimation2::updatePosition()
    {
        m_position += (m_reverse ? -1 : 1);

        if (m_reverse) {
            if (m_position < 0) {
                m_position = (m_loop ? m_total - 1 : 0);
            }
        }
        else {
            if (m_position >= m_total) {
                m_position = (m_loop ? 0 : m_total - 1);
            }
        }

    }
}
