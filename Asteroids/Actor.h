#pragma once
#include <SFML/Graphics.hpp>
#include "GameManager.h"


class Actor
{
public:
	char* TextureLocation;
	sf::Texture Texture;
	sf::Sprite Sprite;
	static GameManager* Manager;

public:
	Actor(GameManager* Manager);

protected:
	virtual void Hit();
	virtual void FrameTime(float dt);
	bool CollidedWith(sf::Sprite Other);
};

