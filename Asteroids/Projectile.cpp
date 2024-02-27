#include "Projectile.h"

Projectile::Projectile(GameManager* Manager, sf::Vector2f Location, float DirectionForce) : Actor(Manager)
{
	if (Texture.loadFromFile(TextureLocation))
	{
		Sprite = sf::Sprite(Texture);
		Sprite.setPosition(Location);
	}
}

Projectile::~Projectile()
{
}

void Projectile::Hit()
{
}
