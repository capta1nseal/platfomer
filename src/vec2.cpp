#include "vec2.hpp"


Vec2::Vec2(double x__, double y__)
{
    x = x__;
    y = y__;
}
Vec2::~Vec2()
{
}

bool Vec2::operator==(const Vec2& other) const
{
    return x == other.x && y == other.y;
}

Vec2 Vec2::operator+(const Vec2& other) const
{
    return Vec2(x + other.x, y + other.y);
}
Vec2 Vec2::operator+(double scalar) const
{
    return Vec2(x + scalar, y + scalar);
}

Vec2 Vec2::operator-(const Vec2& other) const
{
    return Vec2(x - other.x, y - other.y);
}
Vec2 Vec2::operator-(double scalar) const
{
    return Vec2(x - scalar, y - scalar);
}
Vec2 Vec2::operator-() const
{
    return Vec2(-x, -y);
}

double Vec2::operator*(const Vec2& other) const
{
    return x * other.x + y * other.y;
}
Vec2 Vec2::operator*(double scalar) const
{
    return Vec2(x * scalar, y * scalar);
}
Vec2 Vec2::operator/(double scalar) const
{
    return Vec2(x / scalar, y / scalar);
}

Vec2& Vec2::operator+=(const Vec2& other)
{
    x += other.x;
    y += other.y;
    return *this;
}
Vec2& Vec2::operator+=(double scalar)
{
    x += scalar;
    y += scalar;
    return *this;
}

Vec2& Vec2::operator-=(const Vec2& other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}
Vec2& Vec2::operator-=(double scalar)
{
    x -= scalar;
    y -= scalar;
    return *this;
}

Vec2& Vec2::operator*=(const Vec2& other)
{
    x *= other.x;
    y *= other.y;
    return *this;
}
Vec2& Vec2::operator*=(double scalar)
{
    x *= scalar;
    y *= scalar;
    return *this;
}

Vec2& Vec2::operator/=(const Vec2& other)
{
    x /= other.x;
    y /= other.y;
    return *this;
}
Vec2& Vec2::operator/=(double scalar)
{
    x /= scalar;
    y /= scalar;
    return *this;
}
