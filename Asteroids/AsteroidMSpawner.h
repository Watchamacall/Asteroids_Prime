#pragma once
#include <vector>
#include "Asteroid.h"
#include "Random.h"

class GameManager;

class AsteroidMSpawner
{
public:
	AsteroidMSpawner();

	virtual void FrameCall(float dt);
protected:
	float spawnsPerSecond = 2.f;
	float timeSinceLastSpawn;
};

