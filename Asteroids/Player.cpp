#include "Actor.h"
#include "GameManager.h"
#include "Player.h"

Player::Player(GameManager* Manager) : Actor(Manager)
{

}

void Player::Move(float MoveDirection)
{
	if (MoveDirection > 0)
	{
		Sprite.move(GameManager::DegreesToVector2f(Sprite.getRotation() * Manager->dt.asSeconds()));
		//Play Sound
	}

	if (Sprite.getPosition().x > Manager->Window->getSize().x || Sprite.getPosition().x < 0) //If Player X coords are greater than the WindowSize (Right of Screen) or less than 0 (Left of Screen)
	{
		//Wrap around to the other side of the screen, basically if less than 0 then it would be the WindowSize, keeping the y
	}
	if (Sprite.getPosition().y > Manager->Window->getSize().y || Sprite.getPosition().y < 0) //If Player Y coords are greater than WindowSize (Bottom of Screen) or less than 0 (Top of screen)
	{
		//Wrap around to the other side of the screen, basically if less than 0 then it would be WindowSize, keeping the x
	}
}

void Player::Rotate(float RotateAngle)
{
	Sprite.rotate(RotateAngle * (RotateSpeed * Manager->dt.asSeconds()));
}

void Player::Shoot()
{
	Projectile* NewProjectile = Manager->Spawn<Projectile>(Sprite.getPosition(), Sprite.getRotation());
	//Play Sound
}

void Player::Input(sf::Event InputEvent)
{
	switch (InputEvent.key.code)
	{
	case sf::Keyboard::W:
		Move(1);
		break;
	case sf::Keyboard::A:
		Rotate(-1);
		break;
	case sf::Keyboard::S:
		break;
	case sf::Keyboard::D:
		Move(1);
		break;
	case sf::Keyboard::Space:
		Shoot();
		break;
	default:
		break;
	}
}

void Player::Hit(Actor* Other)
{

}
