#pragma once
#include "Actor.h"
class Projectile : public Actor
{
protected:
	float Velocity;

public:
	Projectile(GameManager* Manager, sf::Vector2f Location, float DirectionForce);
	~Projectile();
	virtual void Hit() override;
};

