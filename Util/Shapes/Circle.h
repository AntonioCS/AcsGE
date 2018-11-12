#pragma once

#include "Shape.h"

namespace AcsGameEngine::Util::Shapes {

    class Radius {
    public:

        Radius(float r) : m_radius(r) {
            if (r < 0) {
                m_radius = 0;
            }
        }
        
        void operator-=(int value) {
            if (m_radius - value >= 0) {
                m_radius -= value;
            }    
        }

        void operator+=(int value) {            
            m_radius += value;            
        }

        operator int() const { 
            return static_cast<int>(m_radius);
        }

        float squared() const noexcept 
        {
            return m_radius * m_radius;
        }
    private:
        float m_radius;
    };

    class Circle : public Shape {
    public:
        Radius radius{ 0 };

        double circumference() const noexcept;
        double area() const noexcept override;

        using Shape::Shape;
        Circle(Vector2D, Radius);
    };
};
