#include "Color.h"

namespace AcsGameEngine::Util {

    bool Color::operator!=(const Color &rhs) const {
        return !(operator==(rhs));
    }
    bool Color::operator==(const Color &rhs) const {
        return rhs.r == r && rhs.g == g && rhs.b == b && rhs.a == a;
    }

    Color Color::alphaPercentage(unsigned int value) const noexcept {
        Color c = *this;

        c.a = value * maxAlphaValue / 100;

        return c;
    }

    Color::Color(int r, int g, int b) : r(r), b(b), g(g)
    {
    }

    Color::Color(int r, int g, int b, const char *hex) : Color(r, g, b)
    {
        hex = hex;
    }

    Color::Color(int r, int g, int b, int alpha) : Color(r, g, b, "")
    {
        a = alpha;
    }
    
    Color::Color(const Color &other)
    {
        r = other.r;
        g = other.g;
        b = other.b;
        a = other.a;
        hex = other.hex;
    }

    Color &Color::operator=(const Color &other)
    {
        if (&other != this) {
            r = other.r;
            g = other.g;
            b = other.b;
            a = other.a;
            hex = other.hex;
        }

        return *this;
    }
}