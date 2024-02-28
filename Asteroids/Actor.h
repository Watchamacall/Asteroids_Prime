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

	~Actor();

	virtual void FrameTime(float dt);
	/*
	* Called when this has been Hit
	*/
	virtual void Hit(Actor* Other);
	/*
	* Returns true if this has collided with Other
	*/
	bool CollidedWith(Actor* Other);
};

