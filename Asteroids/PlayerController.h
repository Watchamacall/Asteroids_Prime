#pragma once
#include <functional>
#include <iostream>
#include "KeyBindings.h"
#include "InputListener.h"
#include "Projectile.h"
#include "GameManager.h"

class APlayer;

/*
* Handles all inputs for the Player and moves accordingly
*/
class PlayerController
{
public:
	PlayerController(Actor* actorToControl);

	virtual void FrameCall(float dt);

protected:
	KeyBindings* bindings;
	Actor* controllingActor;
	float forwardSpeed = 500.f;
	float rotationSpeed = 250.f;

	InputListener* forward = nullptr;
	InputListener* right = nullptr;
	InputListener* left = nullptr;
	InputListener* shoot = nullptr;
	
public:
	void MoveCharacter(float moveDirection);

	void RotateCharacter(float rotationDirection);

	void WrapCheck();

	void ShootProjectile();
};

