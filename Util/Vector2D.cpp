#include "Vector2D.h"
namespace AcsGameEngine::Util {

	Vector2D::Vector2D(float x, float y) : m_x(x), m_y(y) {}
	Vector2D::Vector2D(const Vector2D& other) : m_x(other.m_x), m_y(other.m_y) {}
	Vector2D::Vector2D(Vector2D &&other) : m_x(std::move(other.m_x)), m_y(std::move(other.m_y)) {}

	Vector2D &Vector2D::operator=(const Vector2D &other) {
		if (this != &other) {
			m_x = other.m_x;
			m_y = other.m_y;
		}

		return *this;
	}
	Vector2D& Vector2D::operator=(Vector2D &&other) {
		if (this != &other) {
			throw "NOT IMPLEMENTED";
		}

		return *this;
	}

	Vector2D::~Vector2D() {}

	//++Vector2D
	Vector2D& Vector2D::operator++()
	{
		m_x++;
		m_y++;
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
		m_x += rhs.m_x;
		m_y += rhs.m_y;

		return *this;
	}

	Vector2D operator+(Vector2D lhs, const Vector2D& rhs)
	{
		lhs += rhs;
		return lhs;
	}

	Vector2D &Vector2D::operator-=(const Vector2D& rhs) {
		m_x -= rhs.m_x;
		m_y -= rhs.m_y;

		return *this;
	}

	Vector2D operator-(Vector2D lhs, const Vector2D& rhs) {
		lhs -= rhs;
		return lhs;
	}


	float Vector2D::getX() const noexcept {
		return m_x;
	}

	float Vector2D::getY() const noexcept {
		return m_y;
	}

}