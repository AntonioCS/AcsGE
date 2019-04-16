#include "Rectangle.h"

namespace AcsGameEngine::Util::Shapes {

    double Rectangle::area() const noexcept
    {
        return size.w * size.h;
    }

    float Rectangle::rightSide() const noexcept
    {
        return origin.getX() + size.w;
    }

    float Rectangle::bottomSide() const noexcept
    {
        return origin.getY() + size.h;
    }

    Rectangle::Rectangle(Vector2D v, Size d) : Shape::Shape(v), size(d)
    {
    }
}