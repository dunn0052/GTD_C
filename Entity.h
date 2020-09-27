#pragma once
#include <stdio.h>
#include <array>
#include "Component.h"

class Entity
{
public:
	Entity();
	~Entity();

	bool isActive() { return active; }
	void setID(size_t ID) { _ID = ID; }
private:
	bool active = false;
	Component* components[maxComponents] = { 0 };
	size_t _ID = -1;
};
