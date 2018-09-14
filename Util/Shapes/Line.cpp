#include "Line.h"

namespace AcsGameEngine::Util::Shapes {
    Line::Line() {};
    Line::Line(Vector2D o, Vector2D d) : Shape::Shape(o), destination(d) {}
}
