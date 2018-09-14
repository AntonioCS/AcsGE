#define _USE_MATH_DEFINES
#include <cmath>

#include "Circle.h"

namespace AcsGameEngine::Util::Shapes {

    double Circle::circumference() const noexcept 
    {
        return (2 * M_PI * radius);
    }

    double Circle::area() const noexcept
    {
        return (M_PI * radius.squared());
    }
    Circle::Circle(Vector2D c, Radius r) : Shape::Shape(c), radius(r)
    {

    }
}
