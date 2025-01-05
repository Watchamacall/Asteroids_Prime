#pragma once
#include "Actor.h"
class AAsteroid : public Actor
{
public:
	AAsteroid();
	AAsteroid(const std::string& actorName, const std::string& textureLocation) : Actor(actorName, textureLocation) {};
};

