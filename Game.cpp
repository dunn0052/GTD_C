#pragma once
#include "Game.h"
#include "Constants.h"



#pragma region Managers

	TextureManager* Game::textureManager = nullptr;
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
			/* @TODO  change outputs to debug */
			std::cout << "Subsystems Initialised!.." << std::endl;

			if (window = SDL_CreateWindow(title, xpos, ypos, width, height, flags))
			{
				/* Window creation succeeded */
				std::cout << "Window created!" << std::endl;
			}
			else
			{
				/* window creation failed somehow */
				std::cout << "Window creation failed! Exiting" << std::endl;
				isRunning = false;
				return;
			}

			if (renderer = SDL_CreateRenderer(window, -1, 0))
			{
				/* Start screen as red to show creation */
				SDL_SetRenderDrawColor(renderer, GREEN_OPAQUE);
				textureManager = &TextureManager::TextureManager(renderer);
				std::cout << "Renderer created!" << std::endl;
			}
			else
			{
				/* Rndering faild */
				std::cout << "Renderer creation failed!" << std::endl;
				isRunning = false;
				return;
			}

			/* load levels here */

			// Successful game setup
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

			/* do events on frame loop*/
			handleEvents();
			update();
			render();
			/* end frame loop process */

			/* delay for stable frame rate */
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
		/* Level manager update */
	}

	void Game::render()
	{
		SDL_RenderClear(renderer);
		// call level manager draw
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



