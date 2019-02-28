#pragma once

#include "../Vector2D.h"
#include "../Color.h"
#include "../ColorList.h"

namespace AcsGameEngine::Util::Shapes {    

    class Shape {
    public:
        Vector2D origin;
        Color borderColor{ ColorList::_nocolor };
        Color innerColor{ ColorList::_nocolor };
        bool fill{ false };

        virtual double area() const noexcept { return 0.0; }

        Shape() = default;
        Shape(Vector2D o) : origin(o) {}
        virtual ~Shape() = default;

        //@TODO add angle/radians
    };
}