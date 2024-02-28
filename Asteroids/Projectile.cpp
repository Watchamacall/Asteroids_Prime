#include "Projectile.h"
#include "GameManager.h"

Projectile::Projectile(GameManager* Manager, sf::Vector2f Location, float DirectionForce) : Actor(Manager)
{
	if (Texture.loadFromFile(TextureLocation))
	{
		Sprite = sf::Sprite(Texture);
		Sprite.setPosition(Location);
		MoveVector = GameManager::DegreesToVector2f(DirectionForce);
	}
}

Projectile::~Projectile()
{
	Actor::~Actor();
}

void Projectile::FrameTime(float dt)
{
	Actor::FrameTime(dt);

	Sprite.move(MoveVector * (Velocity * dt));
}

void Projectile::Hit(Actor* Other)
{
	
}
