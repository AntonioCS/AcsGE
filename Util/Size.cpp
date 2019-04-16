#include "Size.h"

namespace AcsGameEngine::Util {
    Size::Size(float width, float height) :w(width), h(height)
    {
    }

    Size::Size(int width, int height) : Size(static_cast<float>(width), static_cast<float>(height))
    {
    }

    Size::Size(const Size& other) : w(other.w), h(other.h) { }

    Size::Size(Size &&other) noexcept : w(other.w), h(other.h) {}

    Size &Size::operator=(const Size &other) {
        if (this != &other) {
            w = other.w;
            h = other.h;
        }

        return *this;
    }
    Size& Size::operator=(Size &&other) noexcept {
        if (this != &other) {
            w = other.w;
            h = other.h;
        }

        return *this;
    }

    //++Size
    Size& Size::operator++()
    {
        w++;
        h++;
        return *this;
    }

    //Size++
    Size Size::operator++(int)
    {
        Size tmp(*this); // copy
        operator++(); // pre-increment
        return tmp;   // return old value
    }

    Size &Size::operator+=(const Size& rhs) {
        w += rhs.w;
        h += rhs.h;

        return *this;
    }

    Size &Size::operator-=(const Size& rhs) {
        w -= rhs.w;
        h -= rhs.h;

        return *this;
    }

    Size& Size::operator*=(const Size& rhs)
    {
        w *= rhs.w;
        h *= rhs.h;

        return *this;
    }

    Size& Size::operator/=(const Size& rhs)
    {
        w /= rhs.w;
        h /= rhs.h;

        return *this;
    }

    int Size::getWint() const noexcept
    {
        return static_cast<int>(w);
    }

    int Size::getHint() const noexcept
    {
        return static_cast<int>(h);
    }

    std::pair<int, int> Size::getWHint() const noexcept
    {
        return {getWint(), getHint()};
    }

    Size Size::operator*(const float &v) const noexcept
    {
        return { w * v, h * v };
    }

    Size Size::operator*(const Size& v) const noexcept
    {
        return { w * v.w, h * v.h };
    }

    Size Size::operator/(const float &v) const noexcept
    {
        return { w / v, h / v };
    }

    Size Size::operator-() const noexcept
    {
        return { -w, -h };
    }

    Size Size::operator+(const float& v) const
    {
        return { w + v, h + v };
    }
}
