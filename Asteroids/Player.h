#pragma once
#include "Projectile.h"

class Actor;

class Player : public Actor
{
protected:
	float MoveSpeed = 10.f;
	float RotateSpeed = 10.f;


public:
	Player(GameManager* Manager);

	void Move(float MoveDirection);
	void Rotate(float RotateAngle);
	void Shoot();

	void Input(sf::Event InputEvent);
	virtual void Hit(Actor* Other) override;
};

