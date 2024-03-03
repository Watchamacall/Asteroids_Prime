#include "Projectile.h"
#include "GameManager.h"
#include "Asteroid.h"
Projectile::Projectile(GameManager* Manager, const char* TextureLoc) : Actor(Manager, TextureLoc)
{
	if (Texture.loadFromFile(TextureLocation))
	{
		Sprite = sf::Sprite(Texture);
		/*Sprite.setPosition(Location);
		MoveVector = GameManager::DegreesToVector2f(DirectionForce);*/
	}
}

Projectile::~Projectile()
{
}

void Projectile::FrameTime(float dt)
{
	Actor::FrameTime(dt);

	Sprite.move(MoveVector * (Velocity * dt));
	CurAliveTime += dt;

	if (CurAliveTime >= MaxAliveTime)
	{
		Manager->Remove(this);
	}
}

void Projectile::Hit(Actor* Other)
{
	if (!dynamic_cast<Asteroid*>(Other))
	{
		return;
	}

	Manager->Remove(this);
}
