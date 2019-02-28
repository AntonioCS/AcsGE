#include <utility> //std::pair

#include "CollisionDetection.h"

#include "Shapes/Rectangle.h"
#include "Shapes/Circle.h"
#include "Shapes/Line.h"
#include <iostream>

namespace AcsGameEngine::Util {
    using AcsGameEngine::Util::Shapes::Circle;
    using AcsGameEngine::Util::Shapes::Rectangle;

    //http://lazyfoo.net/tutorials/SDL/27_collision_detection/index.php
    bool CollisionDetection::checkCollision(const Rectangle &rectA, const Rectangle &rectB) noexcept
    {
        return !(
            rectA.bottomSide() <= rectB.origin.y ||
            rectA.origin.y >= rectB.bottomSide() ||
            rectA.rightSide() <= rectB.origin.x ||
            rectA.origin.x >= rectB.rightSide()
            );
    }

    namespace {
        double distanceSquared(std::pair<int, int> xy1, std::pair<int, int> xy2)
        {
            const int deltaX = xy2.first - xy1.first;
            const int deltaY = xy2.second - xy1.second;

            return deltaX * deltaX + deltaY * deltaY;
        }
    }

    //http://lazyfoo.net/tutorials/SDL/29_circular_collision_detection/index.php
    bool CollisionDetection::checkCollision(const Circle &circleA, const Circle &circleB) noexcept
    {
        int totalRadiusSquared = circleA.radius + circleB.radius;
        totalRadiusSquared = totalRadiusSquared * totalRadiusSquared;

        return (distanceSquared(circleA.origin.getXYint(), circleB.origin.getXYint()) < (totalRadiusSquared));
    }

    bool CollisionDetection::checkCollision(const Rectangle &rect, const Circle &circle) noexcept
    {
        //Closest point on collision box        
        auto[cX, cY] = circle.origin.getXYint();
        
        //Find closest x offset
        if (cX < rect.origin.x) {
            cX = static_cast<int>(rect.origin.x);
        }
        else if (cX > rect.rightSide()) {
            cX = static_cast<int>(rect.rightSide());
        }
        
        //Find closest y offset
        if (cY < rect.origin.y) {
            cY = static_cast<int>(rect.origin.y);
        }
        else if (cY > rect.bottomSide()) {
            cY = static_cast<int>(rect.bottomSide());
        }

        //If the closest point is inside the circle
        return (distanceSquared(circle.origin.getXYint(), { cX, cY }) < circle.radius.squared());        
    }
    bool CollisionDetection::checkCollision(const Shapes::Circle &circle, const Shapes::Rectangle &rect) noexcept
    {
        return checkCollision(rect, circle);
    }

    //https://www.topcoder.com/community/data-science/data-science-tutorials/geometry-concepts-line-intersection-and-its-applications/#line_line_intersection
    bool CollisionDetection::checkCollision(const Shapes::Line &lineA, const Shapes::Line &lineB) noexcept
    {
        const auto[lineA_x0, lineA_y0] = lineA.origin.getXYint();
        const auto[lineA_x1, lineA_y1] = lineA.destination.getXYint();

        const auto lineA_A = lineA_y1 - lineA_y0;
        const auto lineA_B = lineA_x0 - lineA_x1;
        const auto lineA_C = lineA_A + lineA_B;

        const auto[lineB_x0, lineB_y0] = lineB.origin.getXYint();
        const auto[lineB_x1, lineB_y1] = lineB.destination.getXYint();

        const auto lineB_A = lineB_y1 - lineB_y0;
        const auto lineB_B = lineB_x0 - lineB_x1;
        const auto lineB_C = lineB_A + lineB_B;


        auto det = lineA_A * lineB_B - lineB_A * lineA_B;
        if (det != 0)
        {
            auto x = (lineB_B * lineA_C - lineA_B * lineB_C) / det;
            auto y = (lineA_A * lineB_C - lineB_A * lineA_C) / det;
            std::cout << "Collision X: " << x << " Y: " << y << '\n';

            return true;
        }
        else
        {
            return false;
        }

    }
}
