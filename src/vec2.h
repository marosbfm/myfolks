#ifndef VEC2_H
#define VEC2_H

#include <cmath>
#include <iostream>

struct Vec2
{
    float x = 0, y = 0;

    Vec2() = default;
    Vec2(float x, float y) : x(x), y(y) {}
    Vec2(const Vec2& other) : x(other.x), y(other.y) {}

    Vec2 operator+(const Vec2& other) const
    {
        return {x + other.x, y + other.y};
    }
    Vec2 operator-(const Vec2& other) const
    {
        return {x - other.x, y - other.y};
    }
    Vec2 operator*(const float& other) const
    {
        return {x * other, y * other};
    }
    Vec2 operator/(const float& other) const
    {
        return {x / other, y / other};
    }

    Vec2& operator+=(const Vec2& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vec2& operator-=(const Vec2& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vec2& operator*=(const float& other)
    {
        x *= other;
        y *= other;
        return *this;
    }

    Vec2& operator/=(const float& other)
    {
        x /= other;
        y /= other;
        return *this;
    }

    float length() const
    {
        return std::sqrt(x * x + y * y);
    }

    Vec2 normalize() const
    {
        float len = std::sqrt(x * x + y * y);
        if (len == 0)
            return {0, 0};
        return {x / len, y / len};
    }
};

inline std::ostream& operator<<(std::ostream& os, const Vec2& vec)
{
    os << "(" << vec.x << ", " << vec.y << ")";
    return os;
}

#endif