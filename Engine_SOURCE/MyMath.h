#pragma once
#include <iostream>

namespace Game
{
	namespace Math
	{
		struct Vector2
		{
		public:
			Vector2()
				: Vector2(0, 0) {}
			Vector2(float x, float y)
				: x(x), y(y) {}
			Vector2(const Vector2& other)
				: Vector2(other.x, other.y) {}
			Vector2 Normalize() const
			{
				return Vector2(x, y) / Length();
			}
			float Length() const
			{
				return std::sqrt(x * x + y * y);
			}
			Vector2& operator = (const Vector2& other) 
			{
				x = other.x; y = other.y;
				return *this;
			}
			Vector2& operator+=(const Vector2& other)
			{
				x += other.x; y += other.y;
				return *this;
			}
			Vector2 operator+(const Vector2& other) const
			{
				return Vector2(x + other.x, y + other.y);
			}
			Vector2 operator+(float x) const
			{
				return Vector2(this->x + x, this->y + x);
			}
			Vector2& operator-=(const Vector2& other)
			{
				x -= other.x; y -= other.y;
				return *this;
			}
			Vector2 operator-(const Vector2& other) const
			{
				return Vector2(x - other.x, y - other.y);
			}
			Vector2 operator-(float x) const
			{
				return Vector2(this->x - x, this->y - x);
			}
			Vector2& operator*=(const Vector2& other)
			{
				x *= other.x; y *= other.y;
				return *this;
			}
			Vector2 operator*(const Vector2& other) const
			{
				return Vector2(x * other.x, y * other.y);
			}
			Vector2 operator*(float x) const
			{
				return Vector2(this->x * x, this->y * x);
			}
			Vector2& operator/=(const Vector2& other)
			{
				if (other.x == 0 || other.y == 0)
					assert(0);
				x /= other.x; y /= other.y;
				return *this;
			}
			Vector2 operator/(const Vector2& other) const
			{
				if (other.x == 0 || other.y == 0)
					assert(0);
				return Vector2(x / other.x, y / other.y);
			}
			Vector2 operator/(float x) const
			{
				assert(x);
				return Vector2(this->x / x, this->y / x);
			}
			Vector2& Abs()
			{
				x = std::abs(x);
				y = std::abs(y);
				return *this;
			}
			void Print() const
			{
				std::cout << "x : " << x << " y : " << y << '\n';
			}
			bool operator == (const Vector2& other) const
			{
				return (x == other.x && y == other.y);
			}
			bool operator !=(const Vector2& other) const
			{
				return !(*this == other);
			}

		public:
			float x;
			float y;

		};
	}
}
