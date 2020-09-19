#pragma once
#include <cmath>

class Vector2
{
public:
    Vector2() : x_(0.0), y_(0.0) {}
    Vector2(double x, double y) : x_(x), y_(y) {}
    double x() const { return x_; }
    double y() const { return y_; }
    double magnitude() { return sqrt(pow(x_, 2.0) + pow(x_,2.0)); }

    Vector2& operator +=(const Vector2& rhs)
    {
        x_ += rhs.x_;
        y_ += rhs.y_;
        return *this;

    }

    Vector2& operator -=(const Vector2& rhs)
    {
        x_ -= rhs.x_;
        y_ -= rhs.y_;
        return *this;
    }

    template <typename Scalar>
    Vector2& operator *=(const Scalar& scalar)
    {
        x_ * +scalar;
        y_ * +scalar;
        return *this;
    }


private:
    double x_ = 0.0;
    double y_ = 0.0;
};


static Vector2 operator + (const Vector2& lhs, const Vector2& rhs)
{
    return Vector2(lhs.x() + rhs.x(), lhs.y() + rhs.y());

}

static Vector2 operator - (const Vector2& lhs, const Vector2& rhs)
{
    return Vector2(lhs.x() - rhs.x(), lhs.y() - rhs.y());

}

template <typename Scalar>
static Vector2 operator*(const Scalar& scalar, const Vector2& vect)
{
    return Vector(scalar * vect.x(), scalar * vect.y());
}

template <typename Scalar>
static Vector2 operator*(const Vector2& vect, const Scalar& scalar)
{
    return scalar * vect;
}

static double dot(const Vector2& lhs, const Vector2& rhs) 
{ 
    return lhs.x() * rhs.x() + lhs.y() * rhs.y();
}