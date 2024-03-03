#pragma once
#include "Projectile.h"

class Actor;
class GameManager;

class Player : public Actor
{
public:
	/// <summary>
	/// Is the Player immune from damage?
	/// </summary>
	bool IsImmune = false;

protected:
	/// <summary>
	/// How fast the Player moves along the play area
	/// </summary>
	float MoveSpeed = 240.f;
	/// <summary>
	/// How fast the Player rotates
	/// </summary>
	float RotateSpeed = 90.f;

private:
	bool MoveLeft = false, MoveRight = false, MoveForward = false, ShootOnce = false;

	/// <summary>
	/// How long the Player is invulnerable after taking damage (In Seconds)
	/// </summary>
	const float InvulnerabilityFrames = 3.f;
	
	/// <summary>
	/// The current Time the Player is immune
	/// </summary>
	float ImmuneTime = 0.f;
public:
	Player(GameManager* Manager, const char* TextureLoc = "Assets/Ship.png");

	/// <summary>
	/// Shoots a Projectile from the Player
	/// </summary>
	void Shoot();

	virtual void FrameTime(float dt) override;
	/// <summary>
	/// Controls how the Inputs are handled
	/// </summary>
	/// <param name="InputEvent">The Input chosen, whether it be KeyPressed or KeyReleased</param>
	void Input(sf::Event InputEvent);
	virtual void Hit(Actor* Other) override;
};

