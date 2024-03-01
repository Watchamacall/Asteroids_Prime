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

	/*
	* The Size of the Medium Asteroid
	*/
	const sf::Vector2f MediumAstSize = sf::Vector2f(0.66f, 0.66f);
	/*
	* The Size of the Small Asteroid
	*/
	const sf::Vector2f SmallAstSize = sf::Vector2f(0.33f, 0.33f);

	/*
	* The angle to the left the Asteroid can change
	*/
	const float AstBreakMinAngle = 30.f;
	/*
	* The angle to the right the Asteroid can change
	*/
	const float AstBreakMaxAngle = 30.f;
public:
	float MoveDirection = 0.f;

	virtual void FrameTime(float dt) override;
protected:
	virtual void Hit(Actor* Other) override;
	virtual void Break();
};

