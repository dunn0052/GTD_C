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
	size_t getID() { return _ID; }
	void addComponent(Component *component);
private:
	bool active = false;
	Component* components[maxComponents] = { 0 };
	size_t _ID = -1;
};
