#include "Actor.h"
#include "GameManager.h"
#include "Component.h"

Actor::Actor(const std::string &actorName, const std::string &textureLocation, const sf::Vector2f initialPosition, Actor* owner) : owner(owner)
{
	SetPosition(initialPosition);

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
	collider = sprite.getGlobalBounds();
	float newHeight = collider.height * collisionMultiplication;
	float differenceHeight = collider.height - newHeight;
	collider.height = newHeight;
	collider.top += differenceHeight / 2;
	
	float newWidth = collider.width * collisionMultiplication;
	float differenceWidth = collider.width - newWidth;
	collider.width = newWidth;
	collider.left += differenceWidth / 2;

	for (auto& component : components)
	{
		component->FrameCall(dt);
	}
}

sf::Vector2f const Actor::GetRightVector()
{
	float radians = sprite.getRotation() * (M_PI / 180.f);

	float forwardX = std::cos(radians);
	float forwardY = std::sin(radians);
    return sf::Vector2f(forwardX, forwardY);
}

sf::Vector2f const Actor::GetForwardVector() 
{
    float rotationDegrees = sprite.getRotation();
    float rotationRadians = rotationDegrees * (M_PI / 180.0f);

    float rightX = std::sin(rotationRadians);
    float rightY = -std::cos(rotationRadians);

    return sf::Vector2f(rightX, rightY);
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

bool Actor::Intersects(Actor *otherActor)
{
	return collider.intersects(otherActor->collider);
}

void Actor::TryCollision(Actor *other)
{
	if (!IsCollisionEnabled() || !other->IsCollisionEnabled())
	{
		return;
	}
	
	auto foundActor = std::find_if(collidingActors.begin(), collidingActors.end(), [&](Actor* actor) 
	{
        return actor == other;
    });

	//If the actor has not been found but we intersect
	if (foundActor == collidingActors.end() && Intersects(other))
	{
		collidingActors.push_back(other);
		OnCollisionStarted(other);
	}
	//If the actor has been found but we do not intersect anymore
	else if (foundActor != collidingActors.end() && !Intersects(other))
	{
		collidingActors.erase(foundActor);
		OnCollisionEnded(other);
	}
}

void Actor::OnCollisionStarted(Actor *other)
{
}

void Actor::OnCollisionEnded(Actor *other)
{
}

void Actor::DestroyActor()
{
	toBeDestroyed = true;
	// std::cout << "Set Actor " << GetName() << " to be destroyed!" << std::endl;
	SetCollision(false);
	// GameManager::GetInstance().GetActorManager()->destroyActor(*this);
}
