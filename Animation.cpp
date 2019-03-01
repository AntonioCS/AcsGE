#include "Animation.h"
#include <iostream>
#include <algorithm> // std::for_each

namespace AcsGameEngine {
    void Animation::applyToFrames(std::chrono::milliseconds value)
    {
        std::for_each(
            m_frames.begin(),
            m_frames.end(),
            [&value](std::pair<Sprite, std::chrono::milliseconds> &frame) {
            frame.second += value;
        }
        );
    }

    Animation::Animation(
        const std::string name,
        Texture & texture) : m_name(name), m_texture(texture)
        //, m_duration(0ms)
    {
    }

    Animation::Animation(
        const std::string name,
        Texture &texture,
        SDL_Rect start,
        unsigned totalFrames,
        SDL_Rect moveBy,
        std::chrono::milliseconds duration
    ) : Animation(name, texture)
    {
        while (totalFrames--) {
            m_frames.emplace_back(Sprite(&m_texture, start), duration);

            start.x += moveBy.x;
            start.y += moveBy.y;
            start.w += moveBy.w;
            start.h += moveBy.h;
        }
    }

    size_t Animation::totalFrames() const noexcept
    {
        return m_frames.size();
    }

    void Animation::add(SDL_Rect rect, std::chrono::milliseconds duration)
    {
        m_frames.emplace_back(Sprite{ &m_texture, rect }, duration);
    }
    void Animation::play()
    {
        m_timer.start();

        m_position = 0;
        m_running = true;
    }

    void Animation::stop() {
        m_timer.stop();

        m_running = false;
        m_position = 0;
    }

    Sprite &Animation::get() {
        if (m_running == false) {
            play();
        }

        const auto currentFrameDuration = m_frames.at(m_position).second;

        if (m_timer.elapsed() > currentFrameDuration) {
            m_timer.reset();
            m_position = (m_position + 1) % m_frames.size();
        }

        return m_frames.at(m_position).first;
    }

    Sprite &Animation::get(int position)
    {
        return m_frames.at(position).first;
    }

    void Animation::delayBy(std::chrono::milliseconds value)
    {
        applyToFrames(value);
    }

    void Animation::speedUpBy(std::chrono::milliseconds value)
    {
        value *= -1;
        applyToFrames(value);
    }
}