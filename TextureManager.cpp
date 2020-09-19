#include "TextureManager.h"


TextureManager::TextureManager(SDL_Renderer* renderer)
{
	renderer = renderer;
}

TextureManager::~TextureManager()
{
	SDL_free(renderer);
}

SDL_Texture* TextureManager::LoadTexture(const char* filename)
{
	SDL_Surface* tempSurface = IMG_Load(filename);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return texture;
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dst)
{
	SDL_RenderCopy(renderer, texture, src, dst);
}