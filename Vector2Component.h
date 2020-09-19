#pragma once
#include <cmath>

#include "Component.h"

class Vector2Component : public Component
{

public:

    Vector2Component();
    Vector2Component(double x, double y);
    double x() const { return x_; }
    double y() const { return y_; }
    double magnitude() { return sqrt(pow(x_, 2.0) + pow(x_, 2.0)); }
    double direction() { return atan2(x_, y_); }

    void init() override;
    void update() override;
    void draw() override;
    void SetPos(double x, double y);
    void UpdatePos(double x, double y);

    Vector2Component& operator +=(const Vector2Component& rhs)
    {
        x_ += rhs.x_;
        y_ += rhs.y_;
        return *this;

    }

    Vector2Component& operator -=(const Vector2Component& rhs)
    {
        x_ -= rhs.x_;
        y_ -= rhs.y_;
        return *this;
    }

    template <typename Scalar>
    Vector2Component& operator *=(const Scalar& scalar)
    {
        x_ * +scalar;
        y_ * +scalar;
        return *this;
    }

private:
    double x_ = 0.0;
    double y_ = 0.0;
};



static Vector2Component operator + (const Vector2Component& lhs, const Vector2Component& rhs)
{
    return Vector2Component(lhs.x() + rhs.x(), lhs.y() + rhs.y());

}

static Vector2Component operator - (const Vector2Component& lhs, const Vector2Component& rhs)
{
    return Vector2Component(lhs.x() - rhs.x(), lhs.y() - rhs.y());
}

template <typename Scalar>
static Vector2Component operator*(const Scalar& scalar, const Vector2Component& vect)
{
    return Vector2Component(scalar * vect.x(), scalar * vect.y());
}

template <typename Scalar>
static Vector2Component operator*(const Vector2Component& vect, const Scalar& scalar)
{
    return scalar * vect;
}

static double dot(const Vector2Component& lhs, const Vector2Component& rhs)
{
    return lhs.x() * rhs.x() + lhs.y() * rhs.y();
}