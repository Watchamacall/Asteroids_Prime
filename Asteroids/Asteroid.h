#pragma once
#include "Actor.h"
class Asteroid : public Actor
{
protected:
	const float Velocity;
	const int BreakNum;
	int DestoryScore;

protected:
	virtual void Hit() override;
	virtual void Break();
};

