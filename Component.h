#pragma once
/* all components */
//#include "Vector2Component.h"
//#include "SpriteComponent.h"
#include "Constants.h"
#include <bitset>
#include <stdio.h>
/* Manger that dictates the components */

using ComponentID = std::size_t;
class Entity;

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
	virtual void init();
	/* Perform component action */
	virtual void update();
	virtual void update(int dt);
	/* prevents the manager from updating */
	virtual void deactivate() { isActive = false; }
	virtual void activate() { isActive = true; }
	virtual void setID(size_t ID) { _ID = ID; }
	virtual COMPONENT_TYPE getType() { return type; }
	/* final removal of component */
	virtual ~Component() {}
private:
	/* Index of component in manager's component vector */
	size_t _ID = -1;
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