#include "Projectile.h"
#include "Asteroid.h"
#include "Player.h"
#include "PlayerScore.h"

AProjectile::AProjectile(const std::string &actorName, const std::string &textureLocation, const sf::Vector2f spawnLocation, Actor* owner) : Actor(actorName,textureLocation, spawnLocation, owner)
{
}

void AProjectile::SendInDirection(sf::Vector2f movementDirection)
{
    moveDir = movementDirection;
    SetScale(0.5f);
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
     if (!IsCollisionEnabled())
    {
        return;
    }

    if (AAsteroid* castedOther = dynamic_cast<AAsteroid*>(other))
    {
        if (APlayer* player = dynamic_cast<APlayer*>(GetOwner()))
        {
            player->GetPlayerScore()->AddScore(10);
        }
        {
            /* code */
        }
        
        DestroyActor(); 
    }
}