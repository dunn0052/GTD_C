#pragma once
#include "Game.h"
#include "Constants.h"

#pragma region Managers

TextureManager* Game::textureManager = nullptr;
Manager* manager;

#pragma endregion

#pragma region Constructor

Game::Game()
{

}

Game::~Game()
{
	Game::textureManager->~TextureManager();
}

#pragma endregion

#pragma region Public

/* SHould this be the constructor instead? */
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags |= SDL_WINDOW_FULLSCREEN;
	}

	if (!(SDL_Init(SDL_INIT_EVERYTHING)))
	{
		std::cout << "Subsystems Initialised!.." << std::endl;

		if (window = SDL_CreateWindow(title, xpos, ypos, width, height, flags))
		{
			std::cout << "Window created!" << std::endl;

		}

		if (renderer = SDL_CreateRenderer(window, -1, 0))
		{
			SDL_SetRenderDrawColor(renderer, RED_OPAQUE);
			textureManager = &TextureManager::TextureManager(renderer);
			std::cout << "Renderer created!" << std::endl;
		}

		// Successfull SDL setup
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

}

void Game::run()
{
	while (isRunning)
	{
		frameStart = SDL_GetTicks();

		handleEvents();
		update();
		render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
}


void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
	{
		isRunning = false;
		break;
	}
	default:
	{
		break;
	}
	}

}

void Game::update()
{

}

void Game::render()
{
	SDL_RenderClear(renderer);
	// items to render here
	SDL_RenderPresent(renderer);
}


void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned!" << std::endl;
}

#pragma endregion

