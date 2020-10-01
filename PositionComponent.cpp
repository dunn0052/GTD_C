#include "PositionComponent.h"


void PositionComponent::init(float x, float y)
{
	coordinates = Vector2::Vector2(x, y);
	velocity = Vector2::Vector2(0, 0);
}

void PositionComponent::update(int dt)
{
	coordinates += velocity * dt;
}

void PositionComponent::setCoordinates(float x, float y)
{
	coordinates.set(x, y);
}

void PositionComponent::setVelocity(float x, float y)
{
	velocity.set(x, y);
}
