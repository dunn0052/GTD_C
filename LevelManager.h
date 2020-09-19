#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentID = std::size_t;

/* should be length of COMPONENT_TYPE -2 ?*/
constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

enum COMPONENT_TYPE
{
	COMPONENT_UNREGISTERED = -1,
	COMPONENT_INIT = 0,
	COMPONENT_DRAW = 1,
	COMPONENT_UPDATE = 2,
	COMPONENT_LENGTH = 3
};


inline ComponentID getComponentTypeID()
{
	static ComponentID lastID = 0;
	return lastID++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept
{
	static ComponentID typeID = getComponentTypeID();
	return typeID;
}

class Component
{
public:
	/* reference to holder */
	Entity* entity;
	/* Initialize component */
	void init();
	/* Perform component action */
	void update();
	/* prevents the manager from updating */
	void deactivate() { isActive = false; }
	void activate() { isActive = true; }
	virtual ~Component() {}

	/* Index of component in manager's component vector */
	int ID = -1;
	/* Used to determine if component should be updated
	   and placed to the back of the vector to avoid pulling
	   component in a cpu cache pull
	*/
	bool isActive = false;
	/* initiate component unregistered until created 
	   If not set then do not update 'cause it's an error
	*/
	COMPONENT_TYPE type = COMPONENT_UNREGISTERED;
};

class Entity
{

public:

	bool isActive() const { return active; }
	void destroy() 
	{
		for (Component *c : componentArray)
		{
			c->deactivate();
		}
		active = false; 
	}

	template <typename T> bool hasComponent() const
	{
		return componentBitSet(getComponentTypeID<T>);
	}

	template <typename T, typename... TAargs>
	T& addComponent(TAargs&&... mArgs, COMPONENT_TYPE type)
	{

	}


	template<typename T> T& getComponent() const
	{
		auto ptr(componentArray[getComponentTypeID<T>]())]
		return *static_cast<T*>(ptr);
	}


private:
	bool active = true;

	ComponentArray componentArray;0
	ComponentBitSet componentBitSet;
};

class LevelManager
{


public:
	/* Update all updateable entities */
	void update(COMPONENT_TYPE type)
	{
		for (auto& e : components[type])
		{
			e.update();
		}
	}

	/* Remove entities if not active */
	void refresh()
	{
		entities.erase(std::remove_if(std::begin(entities), std::end(entities),
			[](const std::unique_ptr<Entity>& mEntity)
			{
				return !mEntity->isActive();
			}),
			std::end(entities));
	}

	template <typename T, typename... TAargs>
	T& addComponent(TAargs&&... mArgs, COMPONENT_TYPE type)
	{

		components[type].emplace_back(std::move(c(new T(std::formard<TAargs>(mArgs)...))));
		T c = &components[type].back();
		c->init();
		/* Get index of component */
		c->ID = components[type].size - 1;
		return c;
	}

private:
	// hold pointers to all entities attached to the manager -- should not care about them only components
	std::vector<std::unique_ptr<Entity>> entities;
	// grid of all components
	std::array<std::vector<Component>, COMPONENT_LENGTH> components;
};

