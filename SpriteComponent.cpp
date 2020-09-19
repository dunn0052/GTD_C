#pragma once
#include "SpriteComponent.h"

SpriteComponent::SpriteComponent() = default;
SpriteComponent::SpriteComponent(const char* path)
{
	setTex(path);
}

void SpriteComponent::setTex(const char* path)
{
	texture = Game::textureManager->LoadTexture(path);
}

void SpriteComponent::init()
{
	position = &entity->getComponent<Vector2Component>();

	int w, h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	srcRect = SDL_Rect{ 0, 0, w, h };
	destRect = SDL_Rect{ 0, 0, w, h };
}

void SpriteComponent::update()
{
	destRect.x = (int)position->x();
	destRect.y = (int)position->y();
}

void SpriteComponent::draw()
{
	Game::textureManager->Draw(texture, &srcRect, &destRect);
}