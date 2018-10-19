#pragma once

namespace AcsGameEngine {
    class Renderer;
}

namespace AcsGameEngine::Util {

    namespace Shapes {
        class Shape;
        class Rectangle;
        class Circle;
        class Line;
        class Point;
        class Triangle;
    }
    
    using Shapes::Circle;
    using Shapes::Rectangle;
    using Shapes::Point;
    using Shapes::Line;
    using Shapes::Shape;
    using Shapes::Triangle;

    class Drawer {
        Renderer &m_renderer;

        void createCirclePoints(int, int, int, std::vector<std::pair<int, int>> &) const noexcept;
    public:
        Drawer(Renderer &);

        void DrawCircle(const Circle &) const noexcept;
        void DrawRect(const Rectangle &) const noexcept;
        void DrawPoint(const Point &) const noexcept;
        void DrawLine(const Line &) const noexcept;
        //void DrawLineCustom(const Line &) const noexcept;
        void DrawTriangle(const Triangle &) const noexcept;

        void DrawShape(const Circle &) const noexcept;
        void DrawShape(const Rectangle &) const noexcept;
        void DrawShape(const Point &) const noexcept;
        void DrawShape(const Line &) const noexcept;
        void DrawShape(const Triangle &) const noexcept;
    };

}
