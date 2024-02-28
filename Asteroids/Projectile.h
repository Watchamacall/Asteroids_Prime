#pragma once
#include "Actor.h"
class Projectile : public Actor
{
protected:
	float Velocity;
	sf::Vector2f MoveVector;
public:
	Projectile(GameManager* Manager, sf::Vector2f Location, float DirectionForce);
	~Projectile();

	virtual void FrameTime(float dt) override;
	virtual void Hit(Actor* Other) override;
};

