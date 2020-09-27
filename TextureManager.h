#pragma once
#include "SDL_common.h"

class TextureManager
{

public:
	TextureManager(SDL_Renderer* renderer);
	~TextureManager();

	SDL_Texture* LoadTexture(const char* filename);
	void Draw(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dst);

private:
	SDL_Renderer* renderer = nullptr;
};

