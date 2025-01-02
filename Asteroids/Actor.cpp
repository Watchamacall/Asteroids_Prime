#include "Actor.h"

Actor::Actor(const std::string& textureLocation, const std::string& actorName)
{
	if (!textureLocation.empty())
	{
		texture.loadFromFile(textureLocation);
		name = actorName;
	}
	sprite.setTexture(texture);
	collider = sprite.getGlobalBounds();
}

void Actor::SetTexture(std::string textureLocation)
{
	texture.loadFromFile(textureLocation);
	sprite.setTexture(texture);
}

void Actor::SetTexture(sf::Image image)
{
	texture.loadFromImage(image);
	sprite.setTexture(texture);
}
