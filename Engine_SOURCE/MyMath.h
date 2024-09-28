#pragma once

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
			Vector2 operator+(const Vector2& other)
			{
				return Vector2(x + other.x, y + other.y);
			}
			Vector2& operator-=(const Vector2& other)
			{
				x -= other.x; y -= other.y;
				return *this;
			}
			Vector2 operator-(const Vector2& other)
			{
				return Vector2(x - other.x, y - other.y);
			}
			Vector2& operator*=(const Vector2& other)
			{
				x *= other.x; y *= other.y;
				return *this;
			}
			Vector2 operator*(const Vector2& other)
			{
				return Vector2(x * other.x, y * other.y);
			}
			Vector2& operator/=(const Vector2& other)
			{
				if (other.x == 0 || other.y == 0)
					assert(0);
				x /= other.x; y /= other.y;
				return *this;
			}
			Vector2 operator/(const Vector2& other)
			{
				if (other.x == 0 || other.y == 0)
					assert(0);
				return Vector2(x / other.x, y / other.y);
			}

		public:
			float x;
			float y;

		};
	}
}
