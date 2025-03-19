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
		keyboardHandle = std::make_unique<KeyboardHandle>();

		forward = keyboardHandle->GetKeyBindings()->CreateNewInput("Forward", sf::Keyboard::W);
		forward->onHeld->AddDelegate([this] { MoveCharacter(1); });

		right = keyboardHandle->GetKeyBindings()->CreateNewInput("Right", sf::Keyboard::D);
		right->onHeld->AddDelegate([this] { RotateCharacter(1); });

		left = keyboardHandle->GetKeyBindings()->CreateNewInput("Left", sf::Keyboard::A);
		left->onHeld->AddDelegate([this] { RotateCharacter(-1); });

		shoot = keyboardHandle->GetKeyBindings()->CreateNewInput("Shoot", sf::Keyboard::Space);
		shoot->onPressed->AddDelegate([this] { ShootProjectile(); });

		//Start player in middle of screen
		sf::Vector2u windowSize = GameManager::GetInstance().GetWindowSize();
		owner->SetPosition(sf::Vector2f(windowSize.x / 2, windowSize.y / 2));

	}

	virtual void FrameCall(float dt) override;

protected:
	std::unique_ptr<KeyboardHandle> keyboardHandle;
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

