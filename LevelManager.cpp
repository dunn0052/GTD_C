#include "LevelManager.h"
#include "Entity.h"
#include "Component.h"



LevelManager::LevelManager() { };

LevelManager::~LevelManager() { };

void LevelManager::update(COMPONENT_TYPE type)
{
	for (auto& e : components[type])
	{
		/* TODO: send pointer of dt to avoid copying dt value in each update function */
		e.update();
	}
}

void LevelManager::update(COMPONENT_TYPE type, int dt)
{
	for (auto& e : components[type])
	{
		/* TODO: send pointer of dt to avoid copying dt value in each update function */
		e.update(dt);
	}
}

void LevelManager::refresh()
{
	entities.erase(std::remove_if(std::begin(entities), std::end(entities),
		[](const std::unique_ptr<Entity>& mEntity)
		{
			return !mEntity->isActive();
		}),
		std::end(entities));
}

template <typename C>
void LevelManager::addComponent(C component, size_t entID)
{
	/* component added directly instead of pointer to have contigious memeory */
	components[component.getType()].push_back(component);
	component.init();
	/* Component ID is last index as it's placed on the end */
	component.setID(components[component.getType()].size() - 1);
	entities[entID]->addComponent(std::move(&component));
}

Entity& LevelManager::addEntity()
{
	Entity* e = new Entity();
	entities.emplace_back(std::move(e));
	e->setID(entities.size() - 1);
	return *e;
}
