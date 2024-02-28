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

Actor::~Actor()
{
	delete Manager;
	delete TextureLocation;
}
void Actor::Hit(Actor* Other)
{

}

void Actor::FrameTime(float dt)
{

}

bool Actor::CollidedWith(Actor* Other)
{
	return Sprite.getGlobalBounds().intersects(Other.getGlobalBounds());
}
