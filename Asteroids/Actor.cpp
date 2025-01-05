#include "Actor.h"

Actor::Actor(const std::string& actorName, const std::string& textureLocation)
{
	if (!textureLocation.empty())
	{
		texture.loadFromFile(textureLocation);
		name = actorName;
	}
	sprite.setTexture(texture);
	collider = sprite.getGlobalBounds();
}

void Actor::FrameCall(float dt)
{
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

void Actor::SetPosition(float x, float y)
{
	SetPosition(sf::Vector2f(x, y));
}

void Actor::SetPosition(const sf::Vector2f& newPosition)
{
	sprite.setPosition(newPosition);
}

void Actor::SetRotation(float angle)
{
	sprite.setRotation(angle);
}

void Actor::Rotate(float angle)
{
	sprite.rotate(angle);
}
