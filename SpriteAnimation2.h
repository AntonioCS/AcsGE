#pragma once
#include <vector>
#include "Sprite2.h"
#include <chrono>

namespace AcsGameEngine {
    struct Frame
    {
        Frame(Sprite2 *s, std::chrono::milliseconds d) : sprite(s), delay(d) {}

        Sprite2 *sprite;
        std::chrono::milliseconds delay;
    };

    class SpriteAnimation2
    {
    public:
        SpriteAnimation2() = default;
        //Animation2(Animation2 &&other) : m_initiated(other.m_initiated), m_position(other.m_position), m_total(other.m_total), m_loop(other.m_loop), m_frames(other.m_frames){}
        SpriteAnimation2 &addFrame(Sprite2 *s, std::chrono::milliseconds delay);
        ~SpriteAnimation2() = default;

        void play();
        bool update(std::chrono::milliseconds timeStep);
        Sprite2 *get();
        void reset();
        void reverse();
    private:
        bool m_initiated;
        int m_position;
        int m_total;
        bool m_loop{ true };
        std::vector<Frame> m_frames;
        bool m_reverse{ false };
        std::chrono::milliseconds m_elapsed;

        void updatePosition();
    };
}
