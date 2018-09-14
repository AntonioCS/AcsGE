#include "Rectangle.h"

namespace AcsGameEngine::Util::Shapes {

    double Rectangle::area() const noexcept
    {
        return dimensions.width * dimensions.height;
    }

    float Rectangle::rightSide() const noexcept
    {
        return origin.getX() + dimensions.width;
    }

    float Rectangle::bottomSide() const noexcept
    {
        return origin.getY() + dimensions.height;
    }

    Rectangle::Rectangle(Vector2D v, Dimensions d) : Shape::Shape(v), dimensions(d)
    {
    }
}