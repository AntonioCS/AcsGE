#pragma once

#include "Shape.h"
#include "../Dimensions.h"

namespace AcsGameEngine::Util::Shapes {

    class Rectangle : public Shape
    {
    public:
        Dimensions dimensions;

        double area() const noexcept override;
        float rightSide() const noexcept;
        float bottomSide() const noexcept;

        Rectangle(Vector2D, Dimensions);
    };

}

