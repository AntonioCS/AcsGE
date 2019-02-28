
#include "../Math/Maths.h"
#include "Vector2D.h"

namespace AcsGameEngine::Util {
    Vector2D::Vector2D(float x, float y) : x(x), y(y) {}

    Vector2D::Vector2D(int x, int y) : Vector2D(static_cast<float>(x), static_cast<float>(y))
    {
    }

    Vector2D::Vector2D(const Vector2D& other) : x(other.x), y(other.y) {}
    Vector2D::Vector2D(Vector2D &&other) noexcept : x(other.x), y(other.y) {}

    Vector2D &Vector2D::operator=(const Vector2D &other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }

        return *this;
    }
    Vector2D& Vector2D::operator=(Vector2D &&other) noexcept {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }

        return *this;
    }

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

    Vector2D Vector2D::operator+(const float& v) const
    {
        return { x + v, y + v };
    }

    bool Vector2D::operator==(const Vector2D& v) const noexcept
    {
        return (x == v.x && y == v.y);
    }

    bool Vector2D::operator>=(const Vector2D& v) const noexcept
    {
        return (x >= v.x && y >= v.y);
    }

    //https://www.youtube.com/watch?v=hh-3xLawoYo&index=6&list=PLW3Zl3wyJwWOpdhYedlD-yCB7WQoHf-My
    Vector2D Vector2D::normalized() const noexcept
    {
        return (*this) / length();
    }

    //https://stackoverflow.com/a/2259502/8715
    Vector2D Vector2D::rotate(Vector2D center, double angle) const
    {
        const auto radians = Maths::degreeToRadian(angle);
        const double s = sin(radians);
        const double c = cos(radians);
        auto[currentX, currentY] = getXY();

        // translate point back to origin:
        currentX -= center.x;
        currentY -= center.y;

        // rotate point
        const double xnew = currentX * c - currentY * s;
        const double ynew = currentX * s + currentY * c;

        // translate point back:
        return { 
            static_cast<float>(xnew + center.x), 
            static_cast<float>(ynew + center.y) 
        };
    }

    Vector2D Vector2D::rotate(float centerX, float centerY, double angle) const
    {
        return rotate(Vector2D{ centerX, centerY }, angle);
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

    float Vector2D::distance(const Vector2D &a, const Vector2D &b) noexcept
    {
        return (b - a).length();
    }

    float Vector2D::getX() const noexcept 
    {
        return x;
    }

    float Vector2D::getY() const noexcept 
    {
        return y;
    }

    int Vector2D::getXint() const noexcept
    {
        return static_cast<int>(x);
    }

    int Vector2D::getYint() const noexcept
    {
        return static_cast<int>(y);
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