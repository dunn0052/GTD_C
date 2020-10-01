#pragma once
#include <stdio.h>

#include "SDL_common.h"
#include "TextureManager.h"
#include "Constants.h"
#include "LevelManager.h"
#include "Level.h"
#include "PositionComponent.h"

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void run();
	void handleEvents();
	void update();
	void render();
	void clean();

	static TextureManager* textureManager;
	static LevelManager* levelManager;

private:
	bool isRunning = false;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	static const int FPS = 60;
	static const int frameDelay = 1000 / FPS;
	Uint32 frameStart = 0;
	int frameTime = 0;
	std::vector<Level> levels;
};




