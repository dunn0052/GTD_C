#include "Vector2Component.h"


Vector2Component::Vector2Component() : x_(0), y_(0) {};

Vector2Component::Vector2Component(double x, double y)
{
    x_ = x;
    y_ = y;
}

void Vector2Component::init()
{
    /* nothing to do */
    return;
}

void Vector2Component::update()
{
    /* nothing to do */
    return;
}

void Vector2Component::draw()
{
    /* nothing to do */
    return;
}

void Vector2Component::SetPos(double x, double y)
{
    x_ = x;
    y_ = y;
}

void Vector2Component::UpdatePos(double x, double y)
{
    x_ += x;
    y_ += y;
}
