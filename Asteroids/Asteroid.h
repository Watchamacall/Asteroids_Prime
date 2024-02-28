#pragma once
#include "Actor.h"
class Asteroid : public Actor
{
public:
	Asteroid(GameManager* Manager);

protected:
	const float Velocity = 10.f;
	const int BreakNum = 2;
	int DestoryScore = 20;

public:
	sf::Vector2f MoveDirection = sf::Vector2f(0.f,0.f);

	virtual void FrameTime(float dt) override;
protected:
	virtual void Hit(Actor* Other) override;
	virtual void Break();
};

