#pragma once
#include <vector>
#include "Asteroid.h"
class AsteroidMSpawner
{
public:
	AsteroidMSpawner();

	virtual void FrameCall(float dt);
protected:
	float spawnsPerSecond;
	std::vector<AAsteroid*> spawnedAsteroids;

public:

};

