#include "Asteroid.h"
#include "GameManager.h"
#include "Random.h"

void AAsteroid::FrameCall(float dt)
{
    Actor::FrameCall(dt);
    
    sf::Vector2f movementSpeed = sf::Vector2f(GetForwardVector().x * (asteroidSpeed * dt), GetForwardVector().y * (asteroidSpeed * dt));
    Translate(movementSpeed);
    WrapCheck();
}

void AAsteroid::OnCollisionStarted(Actor *other)
{
    if (!dynamic_cast<AProjectile*>(other))
    {
        return;
    }
    
    if (asteroidSet == 3)
    {
        DestroyActor();
        return;
    }
    for (size_t i = 0; i < 2; i++)
    {
        AAsteroid* newAst = GameManager::GetInstance().GetActorManager()->CreateNewActor<AAsteroid>("Asteroid", "Assets/Asteroid.png");

        newAst->SetAsteroidSize(asteroidSet += 1);
        //Scale NewAsteroid
        switch (newAst->asteroidSet)
        {
        case 1:
            newAst->SetScale(0.66);
            break;
        case 2:
            newAst->SetScale(0.33);
            break;
        default:
            break;
        }

        //Flick in different direction
        newAst->SetRotation(GetRotation() + Random::RandomFloat(-leftMovement, rightMovement));
    }
    
    
}

void AAsteroid::WrapCheck()
{
    sf::Vector2f PlayerPos = GetPosition();
    //If the Player is over the right hand side
    if (PlayerPos.x > GameManager::GetInstance().GetWindowSize().x || PlayerPos.x < 0 ||
        PlayerPos.y > GameManager::GetInstance().GetWindowSize().y || PlayerPos.y < 0)
    {
        DestroyActor();
    }
}
