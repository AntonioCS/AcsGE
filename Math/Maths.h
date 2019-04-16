#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "../Util/Vector2D.h"

namespace AcsGameEngine::Maths
{
    using AcsGameEngine::Util::Vector2D;
    constexpr float fullCircleAngle{360.f};
    constexpr float halfCircleAngle{180.f};

    inline float Approach(const float goal, const float current, const float dt)
    {
        const auto diff = goal - current;

        if (diff > dt) {
            return current + dt;
        }

        if (diff < -dt) {
            return current - dt;
        }

        return goal;
    }

    //http://codetuto.com/2017/02/7-lerping-tricks-need-know-game-developer/
    inline float lerp(const float current_pos, const float end_pos, const float weight)
    {
        return (1.f - weight) * current_pos + weight * end_pos;
    }

    inline Util::Vector2D lerp(Vector2D currentPos, Vector2D endPos, float weight)
    {
        return {
            lerp(currentPos.x, endPos.x, weight),
            lerp(currentPos.y, endPos.y, weight),
        };
    }


    inline double degreeToRadian(double angle)
    {
        return angle * (M_PI / halfCircleAngle);
    }

    inline double radianToDegree(double radian)
    {
        return radian * (halfCircleAngle / M_PI);
    }

    //https://www.gamefromscratch.com/post/2012/11/18/GameDev-math-recipes-Rotating-to-face-a-point.aspx
    inline float rotateToFacePointInAngles(const Vector2D& origin, const Vector2D& other)
    {
        const auto diff{ origin - other };
        auto angle{ radianToDegree(std::atan2(diff.y, diff.x)) };
        /*
        if (angle < 0) {
            angle = fullCircleAngle - (-angle);
        }
        */

        return angle+90.f;
    }

    inline float dotProduct(Vector2D a, Vector2D b)
    {
        return a.x * b.x + a.y*b.y;
    }
}
