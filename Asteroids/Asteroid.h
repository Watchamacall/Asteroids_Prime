#pragma once
#include "Actor.h"

class Asteroid : public Actor
{
public:
	Asteroid(GameManager* Manager, const char* TextureLoc = "Assets/Asteroid.png");
	~Asteroid();

protected:
	/// <summary>
	/// The speed the Asteroid moves at
	/// </summary>
	const float Velocity = 120.f;
	/// <summary>
	/// How many Asteroids this Actor breaks into
	/// </summary>
	const int BreakNum = 2;
	/// <summary>
	/// The Score added once this is hit
	/// </summary>
	int DestoryScore = 20;

	/// <summary>
	/// The size of the Medium Asteroid
	/// </summary>
	const sf::Vector2f MediumAstSize = sf::Vector2f(0.66f, 0.66f);
	/// <summary>
	/// The size of the Small Asteroid
	/// </summary>
	const sf::Vector2f SmallAstSize = sf::Vector2f(0.33f, 0.33f);

	/// <summary>
	/// The angle to left that the next Asteroid can turn
	/// </summary>
	const float AstBreakMinAngle = 30.f;
	/// <summary>
	/// The angle to the right that the next Asteroid can turn
	/// </summary>
	const float AstBreakMaxAngle = 30.f;
public:
	/// <summary>
	/// The angle the Asteroid will move at
	/// </summary>
	float MoveDirection = 0.f;

	virtual void FrameTime(float dt) override;
protected:
	virtual void Hit(Actor* Other) override;
	/// <summary>
	/// Breaks the Asteorid into a set number of pieces
	/// </summary>
	virtual void Break();
};

