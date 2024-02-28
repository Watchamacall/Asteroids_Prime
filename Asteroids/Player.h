#pragma once
#include "Projectile.h"

class Actor;

class Player : public Actor
{
protected:
	float MoveSpeed;
	float RotateSpeed;

public:
	Player(GameManager* Manager);

	void Move(float MoveDirection);
	void Rotate(float RotateAngle);
	void Shoot();

	void Input(sf::Event InputEvent);
	virtual void Hit(Actor* Other) override;
};

