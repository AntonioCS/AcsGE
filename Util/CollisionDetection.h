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
        bool checkCollision(const Shapes::Rectangle &, const Shapes::Rectangle &) const noexcept;
        bool checkCollision(const Shapes::Circle &, const Shapes::Circle &) const noexcept;
        bool checkCollision(const Shapes::Rectangle &, const Shapes::Circle &) const noexcept;
        bool checkCollision(const Shapes::Circle &, const Shapes::Rectangle &) const noexcept;
        bool checkCollision(const Shapes::Line &, const Shapes::Line &) const noexcept;
    };
}