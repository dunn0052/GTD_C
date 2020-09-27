#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
#include "Component.h"
#include "Constants.h"

class LevelManager
{


public:

	LevelManager();
	~LevelManager();

	/* Update components of type */
	void update(COMPONENT_TYPE type);
	void update(COMPONENT_TYPE type, int dt);

	/* Remove entities if not active */
	void refresh();

	template <typename T, typename... TAargs>
	T& addComponent(TAargs&&... mArgs, COMPONENT_TYPE type, size_t endID);

	Entity& addEntity();

private:
	// hold pointers to all entities attached to the manager -- should not care about them only components
	std::vector<std::unique_ptr<Entity>> entities;
	// grid of all components
	std::array<std::vector<Component>, COMPONENT_LENGTH> components;
};


