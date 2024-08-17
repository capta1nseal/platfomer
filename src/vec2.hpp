#ifndef _PLATFORMERVEC2_
#define _PLATFORMERVEC2_


class Vec2
{
public:
    double x, y;

    Vec2(double x = 0.0, double y = 0.0);
    ~Vec2();

    bool operator==(const Vec2& other) const;

    Vec2 operator+(const Vec2& other) const;
    Vec2 operator+(double scalar) const;

    Vec2 operator-(const Vec2& other) const;
    Vec2 operator-(double scalar) const;
    Vec2 operator-() const;

    double operator*(const Vec2& other) const;
    Vec2 operator*(double scalar) const;
    Vec2 operator/(double scalar) const;

    Vec2& operator+=(const Vec2& other);
    Vec2& operator+=(double scalar);

    Vec2& operator-=(const Vec2& other);
    Vec2& operator-=(double scalar);
    // mMltiplicative assignment is element-wise multiplication.
    Vec2& operator*=(const Vec2& other);
    Vec2& operator*=(double scalar);
    // Divisive assignment is element-wise division.
    Vec2& operator/=(const Vec2& other);
    Vec2& operator/=(double scalar);

private:

};


#endif
