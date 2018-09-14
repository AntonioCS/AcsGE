
#include <cmath>
#include "Vector2D.h"

namespace AcsGameEngine::Util {
    Vector2D::Vector2D() {}
    Vector2D::Vector2D(float x, float y) : x(x), y(y) {}
    Vector2D::Vector2D(const Vector2D& other) : x(other.x), y(other.y) {}
    Vector2D::Vector2D(Vector2D &&other) : x(std::move(other.x)), y(std::move(other.y)) {}

    Vector2D &Vector2D::operator=(const Vector2D &other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }

        return *this;
    }
    Vector2D& Vector2D::operator=(Vector2D &&other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }

        return *this;
    }

    Vector2D::~Vector2D() {}

    //++Vector2D
    Vector2D& Vector2D::operator++()
    {
        x++;
        y++;
        return *this;
    }

    //Vector2D++
    Vector2D Vector2D::operator++(int)
    {
        Vector2D tmp(*this); // copy
        operator++(); // pre-increment
        return tmp;   // return old value
    }

    Vector2D &Vector2D::operator+=(const Vector2D& rhs) {
        x += rhs.x;
        y += rhs.y;

        return *this;
    }

    Vector2D &Vector2D::operator-=(const Vector2D& rhs) {
        x -= rhs.x;
        y -= rhs.y;

        return *this;
    }

    Vector2D Vector2D::operator*(float s) const noexcept
    {
        return { x * s, y * s };
    }

    Vector2D Vector2D::operator/(float s) const noexcept
    {
        return { x / s, y / s };
    }

    Vector2D Vector2D::operator-() const noexcept
    {
        return {-x, -y};
    }

    Vector2D Vector2D::operator+(const Vector2D& v) const
    {
        return {x + v.x, y + v.y};
    }

    Vector2D Vector2D::operator-(const Vector2D& v) const
    {
        return { x - v.x, y - v.y };
    }

    //https://www.youtube.com/watch?v=hh-3xLawoYo&index=6&list=PLW3Zl3wyJwWOpdhYedlD-yCB7WQoHf-My
    Vector2D Vector2D::normalized() const noexcept
    {
        return (*this) / length();
    }

    //https://www.youtube.com/watch?v=bk-RyG0KR_I&index=3&list=PLW3Zl3wyJwWOpdhYedlD-yCB7WQoHf-My
    float Vector2D::length() const noexcept
    {
        return sqrt(lengthSqr());
    }

    //https://www.youtube.com/watch?v=DxmGxkhhluU&list=PLW3Zl3wyJwWOpdhYedlD-yCB7WQoHf-My&index=4
    float Vector2D::lengthSqr() const noexcept
    {
        return x * x + y * y;
    }

    float Vector2D::getX() const noexcept {
        return x;
    }

    float Vector2D::getY() const noexcept {
        return y;
    }

    std::pair<float, float> Vector2D::getXY() const noexcept
    {
        return std::pair<float, float>(x, y);
    }

    std::pair<int, int> Vector2D::getXYint() const noexcept
    {
        return std::pair<int, int>(static_cast<int>(x), static_cast<int>(y));
    }
}