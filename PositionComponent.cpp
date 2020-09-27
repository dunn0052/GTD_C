#include "Component.h"
#include "Vector2.h"

class PositionComponent : public Component
{
public:
	void init(float x, float y)
	{
		coordinates = Vector2::Vector2(x, y);
		velocity = Vector2::Vector2(0, 0);
	}

	void update(int dt)
	{
		coordinates += velocity * dt;
	}

	void setCoordinates(float x, float y)
	{
		coordinates.set(x, y);
	}

	void setVelocity(float x, float y)
	{
		velocity.set(x, y);
	}

private:
	Vector2 coordinates;
	Vector2 velocity;

};