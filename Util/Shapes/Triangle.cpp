#include "Triangle.h"

namespace AcsGameEngine::Util::Shapes {
    Triangle::Triangle(Vector2D O, Vector2D A, Vector2D B) : Shape(O)
    {
        lineOA.origin = O;
        lineOA.destination = A;

        lineAB.origin = A;
        lineAB.destination = B;

        lineBO.origin = B;
        lineBO.destination = O;
    }
}
