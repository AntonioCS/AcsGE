#pragma once

#include <utility>

namespace AcsGameEngine::Util {

	class Vector2D {

		float m_x{};
		float m_y{};
	public:
		Vector2D(float x, float y);
		Vector2D(const Vector2D& other);
		Vector2D(Vector2D &&other);

		Vector2D &operator=(const Vector2D &other);
		Vector2D& operator=(Vector2D &&other);
		~Vector2D();

		//++Vector2D
		Vector2D& operator++();

		//Vector2D++
		Vector2D operator++(int);

		Vector2D &operator+=(const Vector2D& rhs);

		friend Vector2D operator+(Vector2D lhs, const Vector2D& rhs);
	
		Vector2D &operator-=(const Vector2D& rhs);

		friend Vector2D operator-(Vector2D const &lhs, const Vector2D& rhs);

		float getX() const noexcept;
		float getY() const noexcept;
	};
}