#pragma once

#include <string>

namespace AcsGameEngine::Util {

    class Color {
    public:
        int r{ -1 };
        int g{ -1 };
        int b{ -1 };

        char *hex = nullptr;

        //alpha
        const unsigned int maxAlphaValue{ 255 };
        unsigned int a{ maxAlphaValue };               
        
        Color() = default;
        Color(int r, int g, int b);
        Color(int r, int g, int b, const char *hex);
        Color(int r, int g, int b, int alpha);
        Color(const std::string &hex);
        Color(const Color &other);

        Color &operator=(const Color &other);
        bool operator!=(const Color &rhs) const;
        bool operator==(const Color &rhs) const;

        Color alphaPercentage(unsigned int value) const noexcept;
    };
}