#include "Actor.h"
#include "GameManager.h"
#include "Player.h"
#include "Asteroid.h"

Player::Player(GameManager* Manager, const char* TextureLoc) : Actor(Manager, TextureLoc)
{

}


void Player::Shoot()
{
	Projectile* NewProjectile = Manager->Spawn<Projectile>(Sprite.getPosition(), Sprite.getRotation());

	NewProjectile->MoveVector = GameManager::DegreesToVector2f(Sprite.getRotation());

	NewProjectile = nullptr;
	//Play Sound
}

void Player::FrameTime(float dt)
{
	Actor::FrameTime(dt);

	if (MoveLeft)
        Sprite.rotate(-RotateSpeed * dt);
    if (MoveRight)
        Sprite.rotate(RotateSpeed * dt);
	if (MoveForward)
		Move(Sprite.getRotation(), MoveSpeed);
	if (IsImmune)
	{
		if (ImmuneTime >= InvulnerabilityFrames)
		{
			IsImmune = false;
			ImmuneTime = 0;
		}
		ImmuneTime += dt;
	}
}

void Player::Input(sf::Event InputEvent)
{
	switch (InputEvent.key.code)
	{
	case sf::Keyboard::W:
		MoveForward = InputEvent.type == sf::Event::KeyPressed;
		break;
	case sf::Keyboard::A:
		MoveLeft = InputEvent.type == sf::Event::KeyPressed;
		break;
	case sf::Keyboard::S:
		break;
	case sf::Keyboard::D:
		MoveRight = InputEvent.type == sf::Event::KeyPressed;
		break;
	case sf::Keyboard::Space:
		if (InputEvent.type == sf::Event::KeyPressed)
		{
			if (ShootOnce)
				return;

			ShootOnce = true;
			Shoot();
		}
		else if (InputEvent.type == sf::Event::KeyReleased)
		{
			ShootOnce = false;
		}
		break;
	default:
		break;
	}
}

void Player::Hit(Actor* Other)
{
	if (!dynamic_cast<Asteroid*>(Other))
		return;
	if (!IsImmune)
		Manager->ResetPlayer();
}
