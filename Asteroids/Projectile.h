#pragma once
#include "Actor.h"
class Projectile : public Actor
{
public:
	/// <summary>
	/// How fast the Projectiles move
	/// </summary>
	const float Velocity = 360.f;
	/// <summary>
	/// How long the Projectile stays alive for
	/// </summary>
	const float MaxAliveTime = 10.f;
	/// <summary>
	/// The current Alive time for this Projectile
	/// </summary>
	float CurAliveTime = 0.f;
	/// <summary>
	/// The MoveVector the Projectile will follow
	/// </summary>
	sf::Vector2f MoveVector;
	/// <summary>
	/// The scale of the Projectile
	/// </summary>
	const sf::Vector2f Scale = sf::Vector2f(0.25f, 0.25f);
public:

	Projectile(GameManager* Manager, const char* TextureLoc = "Assets/Asteroid.png");
	~Projectile();

	virtual void FrameTime(float dt) override;

	virtual void Hit(Actor* Other) override;
};

