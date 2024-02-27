#include "Actor.h"

Actor::Actor(GameManager* Manager)
{
	this->Manager = Manager;
	if (!Texture.loadFromFile(TextureLocation))
	{
		//Handle error with not loading Texture
	}
	Sprite = sf::Sprite(Texture);
}

void Actor::Hit()
{

}

void Actor::FrameTime(float dt)
{
}

bool Actor::CollidedWith(sf::Sprite Other)
{
	return Sprite.getGlobalBounds().intersects(Other.getGlobalBounds());
}
