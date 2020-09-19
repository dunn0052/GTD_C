#pragma once
#include "Game.h"

Game* game = nullptr;

int main(int argc, char* argv[])
{

	game = new Game();
	game->init("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	game->run();

	game->clean();
	return 0;
}