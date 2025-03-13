#pragma once
#include "Actor.h"
#include "Projectile.h"

class GameManager;
class APlayer;
class AAsteroid : public Actor
{
public:
	AAsteroid();
	AAsteroid(const std::string& actorName, const std::string& textureLocation) : Actor(actorName, textureLocation) {};
	AAsteroid(const std::string& actorName, const std::string& textureLocation, const sf::Vector2f initialPosition) : Actor(actorName, textureLocation, initialPosition) {};

protected:
	float asteroidSpeed = 0.5f;
	int asteroidSet = 0;

	sf::Vector2f moveVector; 

	float leftMovement = 45.f;
	float rightMovement = 45.f;

public:
	virtual void FrameCall(float dt) override;

	virtual void OnCollisionStarted(Actor* other) override;
	void SetAsteroidSize(int newSize) { asteroidSet = newSize; }
	void SetAsteroidVector(sf::Vector2f& movementVector) { moveVector = movementVector; }
	void WrapCheck();
};

