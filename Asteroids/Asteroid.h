#pragma once
#include "Actor.h"
#include "Projectile.h"

class GameManager;
class AAsteroid : public Actor
{
public:
	AAsteroid();
	AAsteroid(const std::string& actorName, const std::string& textureLocation) : Actor(actorName, textureLocation) {};

protected:
	float asteroidSpeed = 100.f;
	int asteroidSet = 0;

	float leftMovement = 45.f;
	float rightMovement = 45.f;

public:
	virtual void FrameCall(float dt) override;

	virtual void OnCollisionStarted(Actor* other) override;
	void SetAsteroidSize(int newSize) { asteroidSet = newSize; }
	void WrapCheck();
};

