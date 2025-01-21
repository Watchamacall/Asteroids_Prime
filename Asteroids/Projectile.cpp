#include "Projectile.h"

AProjectile::AProjectile(const std::string &actorName, const std::string &textureLocation) : Actor(actorName,textureLocation)
{
}

void AProjectile::SendInDirection(sf::Vector2f movementDirection)
{
    moveDir = movementDirection;
}

void AProjectile::FrameCall(float dt)
{
    Actor::FrameCall(dt);

    sf::Vector2f movement = sf::Vector2f(moveDir.x * projectileSpeed, moveDir.y * projectileSpeed);
    Translate(movement * dt);

    //If out of bounds
    if (GetPosition().x > GameManager::GetInstance().GetWindowSize().x || GetPosition().y > GameManager::GetInstance().GetWindowSize().y || GetPosition().x < 0 || GetPosition().y < 0)
    {
        DestroyActor();
    }
    
}

void AProjectile::OnCollisionStarted(Actor *other)
{
    if (AAsteroid* castedOther = dynamic_cast<AAsteroid*>(other))
    {
        DestroyActor(); 
    }
    
}
