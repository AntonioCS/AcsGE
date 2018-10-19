
#include <vector>
#include <utility> //std::pair
#include <algorithm> //std::minmax_element
#include <unordered_map>

#include "Drawer.h"
#include "../Renderer.h"

#include "Shapes/Circle.h"
#include "Shapes/Rectangle.h"
#include "Shapes/Point.h"
#include "Shapes/Line.h"
#include "Shapes/Triangle.h"


namespace AcsGameEngine::Util {

    using AcsGameEngine::Renderer;

    void Drawer::createCirclePoints(int x0, int y0, int radius, std::vector<std::pair<int, int>> &pointsDestination) const noexcept
    {
            int x = radius - 1;
            int y = 0;
            int dx = 1;
            int dy = 1;
            int err = dx - (radius << 1);

            while (x >= y)
            {
                pointsDestination.emplace_back(x0 + x, y0 + y);
                pointsDestination.emplace_back(x0 + y, y0 + x);
                pointsDestination.emplace_back(x0 - y, y0 + x);
                pointsDestination.emplace_back(x0 - x, y0 + y);
                pointsDestination.emplace_back(x0 - x, y0 - y);
                pointsDestination.emplace_back(x0 - y, y0 - x);
                pointsDestination.emplace_back(x0 + y, y0 - x);
                pointsDestination.emplace_back(x0 + x, y0 - y);

                if (err <= 0)
                {
                    y++;
                    err += dy;
                    dy += 2;
                }

                if (err > 0)
                {
                    x--;
                    dx += 2;
                    err += dx - (radius << 1);
                }
            }
    }

    Drawer::Drawer(Renderer & r) : m_renderer(r) {}

    //https://gist.github.com/derofim/912cfc9161269336f722
    //https://en.wikipedia.org/wiki/Midpoint_circle_algorithm#C_Example
    void Drawer::DrawCircle(const Circle &circle) const noexcept
    {
        auto[x0, y0] = circle.origin.getXY();
        std::vector<std::pair<int, int>> points;
        createCirclePoints(x0, y0, circle.radius, points);

        if (circle.fill) {
            std::unordered_map<int, std::vector<int>> xPoints;

            for (const auto&[x2, y2] : points) {
                if (xPoints.count(y2)) {
                    xPoints[y2].push_back(x2);
                }
                else {
                    xPoints[y2] = std::vector<int>{ x2 };
                }
            }

            Line line{};
            line.borderColor = circle.innerColor;

            for (const auto &[y, values] : xPoints) {
                if (values.size() >= 2) {
                    const auto[xSmall, xBig] = std::minmax_element(values.begin(), values.end());

                    line.origin.x = static_cast<float>(*xSmall);
                    line.origin.y = static_cast<float>(y);
                    line.destination.x = static_cast<float>(*xBig);
                    line.destination.y = static_cast<float>(y);

                    DrawLine(line);
                }
            }
        }

        Point point{};
        point.borderColor = circle.borderColor;

        for (const auto&[x2, y2] : points) {
            point.origin.x = static_cast<float>(x2);
            point.origin.y = static_cast<float>(y2);

            DrawPoint(point);
        }
    }

    void Drawer::DrawRect(const Rectangle &rect) const noexcept
    {
        auto[x, y] = rect.origin.getXYint();
        auto[w, h] = rect.dimensions.getWHint();

        SDL_Rect sdlRect { x, y, w, h };

        if (rect.fill) {
            m_renderer.DrawColor(rect.innerColor);
            m_renderer.DrawRect(sdlRect, rect.fill);
        }

        if (rect.fill == false || rect.innerColor != rect.borderColor) {
            m_renderer.DrawColor(rect.borderColor);
            m_renderer.DrawRect(sdlRect);
        }
    }

    void Drawer::DrawPoint(const Point &point) const noexcept
    {
        auto[x, y] = point.origin.getXY();
        m_renderer.DrawColor(point.borderColor);
        m_renderer.DrawPoint(x, y);
    }

    void Drawer::DrawLine(const Line &line) const noexcept
    {
        auto[x0, y0] = line.origin.getXYint();
        auto[x1, y1] = line.destination.getXYint();

        m_renderer.DrawColor(line.borderColor);
        m_renderer.DrawLine(x0, y0, x1, y1);
    }    

    //https://www.youtube.com/watch?v=l-u6uxnOmH0&index=2&list=PLqCJpWy5Fohd6Hg5BW8eAjo5SzQQYl43S
         /*
    void Drawer::DrawLineCustom(const Line &line) const noexcept
    {
   
        m_renderer.DrawColor(line.borderColor);

        //if Y dominant 
        //m = slope = rise/run
        //rise = y1 - y0
        //run = x1 - x0
        //b = Y intersect = b = Y -mX
        //Y=mX+b

        //if X dominant 
        //w = run/rise
        //p = X - wY
        //X=wY+p


        auto[x0, y0] = line.origin.getXY();
        auto[x1, y1] = line.destination.getXY();
        const auto isVertical = x1 != x0;
        float m{};

        if (!isVertical) //otherwise we will divide by 0
        {
            m = (y1 - y0) / (x1 - x0); //slope
        }

        //Y dominant 
        if (!isVertical && std::abs(m) <= 1.0f) {
            //x0 must always be the origin
            if (x0 > x1) {
                std::swap(x0, x1);
            }

            const auto b = y0 - m * x0;

            for (auto x = static_cast<int>(x0); x <= x1; x++) {
                const auto y = m * static_cast<float>(x) + b;
                m_renderer.DrawPoint(x, y);
            }
        }
        //X dominant
        else {
            const auto w = (x1 - x0) / (y1 - y0); //slope
            const auto p = x0 - w * y0;

            if (y0 > y1) {
                std::swap(y0, y1);
            }


            for (auto y = static_cast<int>(y0); y <= y1; y++)
            {
                const auto x = w * static_cast<float>(y) + p;
                m_renderer.DrawPoint(x, y);
            }
        }     
        //m_renderer.DrawPoint();
    }
    */
    void Drawer::DrawTriangle(const Triangle &triangle) const noexcept
    {
        DrawLine(triangle.lineOA);
        DrawLine(triangle.lineAB);
        DrawLine(triangle.lineBO);
    }

    void Drawer::DrawShape(const Circle &circle) const noexcept 
    {
        DrawCircle(circle);
    }

    void Drawer::DrawShape(const Rectangle &rect) const noexcept 
    {
        DrawRect(rect);
    }

    void Drawer::DrawShape(const Point &point) const noexcept 
    {
        DrawPoint(point);
    }

    void Drawer::DrawShape(const Line &line) const noexcept 
    {
        DrawLine(line);
    }

    void Drawer::DrawShape(const Triangle &tri) const noexcept
    {
        DrawTriangle(tri);
    }
}
