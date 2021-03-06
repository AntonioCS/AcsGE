﻿#pragma once
#include <utility>

namespace AcsGameEngine::Util {

    class Size
    {
    public:
        float w{};
        float h{};

        Size() = default;
        Size(float width, float height);
        Size(int width, int height);
        Size(const Size &other);
        Size(Size &&other) noexcept;
        ~Size() = default;

        Size &operator=(const Size &other);
        Size &operator=(Size &&other) noexcept;
        Size& operator++(); //++Size
        Size operator++(int); //Size++

        Size operator*(const float &v) const noexcept;
        Size operator*(const Size &v) const noexcept;
        Size operator/(const float &v) const noexcept;
        Size operator-() const noexcept;
        Size operator+(const float &v) const;

        Size &operator+=(const Size& rhs);
        Size &operator-=(const Size& rhs);
        Size &operator*=(const Size& rhs);
        Size &operator/=(const Size& rhs);

        int getWint() const noexcept;
        int getHint() const noexcept;
        std::pair<int,int> getWHint() const noexcept;
    };
}
