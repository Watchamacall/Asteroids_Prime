#pragma once
#include <functional>
#include <iostream>
#include "KeyBindings.h"
#include "InputListener.h"
#include "Projectile.h"
#include "GameManager.h"
#include "Component.h"

class APlayer;

/*
* Handles all inputs for the Player and moves accordingly
*/
class PlayerController : public Component
{
public:
	PlayerController(Actor* owner) : Component(owner)
	{
		bindings = GameManager::GetInstance().GetKeybindings();

		forward = bindings->CreateNewInput("Forward", sf::Keyboard::W);
		forward->onHeld->AddDelegate([this] { MoveCharacter(1); });

		right = bindings->CreateNewInput("Right", sf::Keyboard::D);
		right->onHeld->AddDelegate([this] { RotateCharacter(1); });

		left = bindings->CreateNewInput("Left", sf::Keyboard::A);
		left->onHeld->AddDelegate([this] { RotateCharacter(-1); });

		shoot = bindings->CreateNewInput("Shoot", sf::Keyboard::Space);
		shoot->onPressed->AddDelegate([this] { ShootProjectile(); });
	}

	virtual void FrameCall(float dt) override;

protected:
	KeyBindings* bindings;
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

