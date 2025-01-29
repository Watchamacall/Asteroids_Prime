#pragma once
#include <vector>
#include "Random.h"

// class GameManager;
class Asteroid;

class AsteroidMSpawner
{
public:
	AsteroidMSpawner();
	~AsteroidMSpawner() = default;
	
	virtual void FrameCall(float dt);
protected:
	float spawnsPerSecond = 2.f;
	float timeSinceLastSpawn;
};

