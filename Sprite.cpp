#include "Sprite.h"
#include "Game.h"

#define INIT_RECTS() do {\
	int w, h;\
	SDL_QueryTexture(spriteTexture, NULL, NULL, &w, &h);\
	srcRect = SDL_Rect{ (int)coordinates_.x(), (int)coordinates_.y(), w, h };\
	destRect = SDL_Rect{ (int)coordinates_.x(), (int)coordinates_.y(), w, h };\
} while (false)

Sprite::Sprite(const char* textureSheet)
{
	spriteTexture = Game::textureManager->LoadTexture(textureSheet);
	coordinates_ = Vector2();
	INIT_RECTS();
}

Sprite::Sprite(const char* textureSheet, double xpos, double ypos)
{
	spriteTexture = Game::textureManager->LoadTexture(textureSheet);
	coordinates_ = Vector2(xpos, ypos);
	INIT_RECTS();
}

#undef INIT_RECTS

Sprite::~Sprite()
{

}

void Sprite::Render()
{
	Game::textureManager->Draw(spriteTexture, &srcRect, &destRect);
}

void Sprite::Update(double dt)
{

}