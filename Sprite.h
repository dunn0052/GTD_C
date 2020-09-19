#pragma once
#include "SDL_common.h"
#include "Vector2.h"
#include "Constants.h"

class Sprite
{
public:
	Sprite(const char* textureSheet);
	Sprite(const char* textureSheet, double xpos, double ypos);
	~Sprite();

	Vector2 coord() { return coordinates_; };
	double x() { return coordinates_.x(); };
	double y() { return coordinates_.y(); };

	void Update(double dt);
	void Render();

private:
	Vector2 coordinates_;
	SDL_Texture* spriteTexture;
	SDL_Rect srcRect, destRect;
};

