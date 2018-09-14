#pragma once

#include "Shape.h"

namespace AcsGameEngine::Util::Shapes {
    class Line : public Shape {
    public:
        Vector2D destination;

        Line();
        Line(Vector2D origin, Vector2D destination);
    };
}