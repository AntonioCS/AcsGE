#pragma once

#include "Line.h"

namespace AcsGameEngine::Util::Shapes {
    class Triangle : public Shape {
    public:
        Line lineOA;
        Line lineAB;
        Line lineBO;

        Triangle(Vector2D O, Vector2D A, Vector2D B);
        void setBorderColor(const Color&);
        Color getBorderColor() const noexcept;

        void setInnerColor(const Color&);
        Color getInnerColor() const noexcept;

    };
}