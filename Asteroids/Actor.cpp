#include "Actor.h"
#include "GameManager.h"

Actor::Actor(const std::string& actorName, const std::string& textureLocation)
{
	if (!textureLocation.empty())
	{
		texture.loadFromFile(textureLocation);
		name = actorName;
	}
	sprite.setTexture(texture);
	collider = sprite.getGlobalBounds();

	GameManager::GetInstance().GetFrameCallDelegate()->AddVoidDelegate([this] {FrameCall(GameManager::GetInstance().GetDeltaTime());});
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

void Actor::Translate(float x, float y)
{
	Translate(sf::Vector2f(x,y));
}

void Actor::Translate(const sf::Vector2f &moveVector)
{
	sf::Vector2f prevPosition = sprite.getPosition();
	sprite.setPosition(prevPosition += moveVector);
}

void Actor::SetRotation(float angle)
{
	sprite.setRotation(angle);
}

void Actor::Rotate(float angle)
{
	sprite.rotate(angle);
}
