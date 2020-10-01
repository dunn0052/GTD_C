#pragma once
#include "Component.h"
#include "Vector2.h"

class PositionComponent : public Component
{
public:
	void init(float x, float y);
	void update(int dt);
	void setCoordinates(float x, float y);
	void setVelocity(float x, float y);

private:
	Vector2 coordinates;
	Vector2 velocity;

};