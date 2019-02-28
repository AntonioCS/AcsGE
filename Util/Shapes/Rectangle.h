#pragma once

#include "Shape.h"
#include "../Dimensions.h"

namespace AcsGameEngine::Util::Shapes {

    class Rectangle : public Shape
    {
    public:
        Rectangle() = default;
        Rectangle(Vector2D, Vector2D);

        Vector2D size;

        double area() const noexcept override;
        float rightSide() const noexcept;
        float bottomSide() const noexcept;
    };

}

