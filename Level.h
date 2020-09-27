#pragma once
#include "SDL_common.h"
#include "LevelManager.h"

class Level
{

public:
	Level();
	~Level();
private:
	LevelManager* manager;

};

