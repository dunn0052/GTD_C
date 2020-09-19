#pragma once

#include "Component.h"
#include "SDL_common.h"
#include "Game.h"

class SpriteComponent : public Component
{


public:

	SpriteComponent() = default;
	SpriteComponent(const char* path);
	void setTex(const char* path);
	void init() override;
	void update() override;
	void draw() override;

private:
	Vector2Component* position;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
};

