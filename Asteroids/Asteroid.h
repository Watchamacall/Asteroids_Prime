#pragma once
#include "Actor.h"

class GameManager;
class AAsteroid : public Actor
{
public:
	AAsteroid();
	AAsteroid(const std::string& actorName, const std::string& textureLocation) : Actor(actorName, textureLocation) {};

protected:
	float asteroidSpeed = 100.f;

public:
	virtual void FrameCall(float dt) override;
	void WrapCheck();
};

