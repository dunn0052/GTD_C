#include "Entity.h"
#include "Component.h"

Entity::Entity() {}
Entity::~Entity() {}

void Entity::addComponent(Component *component)
{
	/* static cast needed? */
	components[component->getType()] = component;
}