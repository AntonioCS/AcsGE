#include "Rectangle.h"

namespace AcsGameEngine::Util::Shapes {

    double Rectangle::area() const noexcept
    {
        return size.x * size.y;
    }

    float Rectangle::rightSide() const noexcept
    {
        return origin.getX() + size.x;
    }

    float Rectangle::bottomSide() const noexcept
    {
        return origin.getY() + size.y;
    }

    Rectangle::Rectangle(Vector2D v, Vector2D d) : Shape::Shape(v), size(d)
    {
    }
}