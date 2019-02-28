#pragma once

namespace AcsGameEngine::Util {

    namespace Shapes {
        class Circle;
        class Rectangle;
        class Line;
        class Triangle;
    }

    class CollisionDetection {        
    public:
        static bool checkCollision(const Shapes::Rectangle &, const Shapes::Rectangle &) noexcept;
        static bool checkCollision(const Shapes::Circle &, const Shapes::Circle &) noexcept;
        static bool checkCollision(const Shapes::Rectangle &, const Shapes::Circle &) noexcept;
        static bool checkCollision(const Shapes::Circle &, const Shapes::Rectangle &) noexcept;
        static bool checkCollision(const Shapes::Line &, const Shapes::Line &) noexcept;
    };
}