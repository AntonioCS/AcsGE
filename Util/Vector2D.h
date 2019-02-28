#pragma once

#include <utility>
#include <chrono>

namespace AcsGameEngine::Util {
    struct Vector2D {
        float x{};
        float y{};

        Vector2D() = default;
        Vector2D(float x, float y);
        Vector2D(int x, int y);
        Vector2D(const Vector2D &other);
        Vector2D(Vector2D &&other) noexcept;
        ~Vector2D() = default;
        Vector2D &operator=(const Vector2D &other);
        Vector2D &operator=(Vector2D &&other) noexcept;

        Vector2D& operator++(); //++Vector2D
        Vector2D operator++(int); //Vector2D++
        Vector2D &operator+=(const Vector2D& rhs);
        Vector2D &operator-=(const Vector2D& rhs);
        Vector2D operator*(float s) const noexcept;
        Vector2D operator/(float s) const noexcept;
        Vector2D operator-() const noexcept;
        Vector2D operator+(const Vector2D& v) const;
        Vector2D operator-(const Vector2D& v) const;

        Vector2D operator+(const float &v) const;


        bool operator==(const Vector2D&v) const noexcept;
        bool operator>=(const Vector2D&v) const noexcept;
        //Vector2D operator*(std::chrono::milliseconds ms) const noexcept;

        Vector2D normalized() const noexcept;

        Vector2D rotate(Vector2D center, double angle) const;        
        Vector2D rotate(float centerX, float centerY, double angle) const;

        float length() const noexcept;
        float lengthSqr() const noexcept;

        static float distance(const Vector2D &a, const Vector2D &b) noexcept;

        float getX() const noexcept;
        float getY() const noexcept;
        int getXint() const noexcept;
        int getYint() const noexcept;
        std::pair<float, float> getXY() const noexcept;
        std::pair<int, int> getXYint() const noexcept;
    };
}