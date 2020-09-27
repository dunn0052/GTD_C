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

template <typename T, typename... TAargs>
T& LevelManager::addComponent(TAargs&&... mArgs, COMPONENT_TYPE type, size_t entID)
{
	components[type].emplace_back(std::move(c(new T(std::forward<TAargs>(mArgs)...))));
	T c = &components[type].back();
	c->init();
	/* Component ID is last index as it's placed on the end */
	c->ID = components[type].size() - 1;
	return c;
}

Entity& LevelManager::addEntity()
{
	Entity* e = new Entity();
	std::unique_ptr<Entity> uPtr{ e };
	entities.emplace_back(std::move(uPtr));
	e->setID(entities.size() - 1);
	return *e;
}
