#pragma once

#include "Shape.h"
#include "../Size.h"

namespace AcsGameEngine::Util::Shapes {

    class Rectangle : public Shape
    {
    public:
        Rectangle() = default;
        Rectangle(Vector2D, Size);

        Size size;

        double area() const noexcept override;
        float rightSide() const noexcept;
        float bottomSide() const noexcept;
    };

}

