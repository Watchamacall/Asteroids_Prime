#include "Asteroid.h"
#include "GameManager.h"
#include "Player.h"
#include "Random.h"

void AAsteroid::FrameCall(float dt)
{
    Actor::FrameCall(dt);
    
    sf::Vector2f movementSpeed = sf::Vector2f(moveVector.x * asteroidSpeed, moveVector.y * asteroidSpeed);
    Translate(movementSpeed * dt);
    WrapCheck();
}

void AAsteroid::OnCollisionStarted(Actor *other)
{
    if (!IsCollisionEnabled())
    {
        return;
    }
    

    if (!dynamic_cast<AProjectile*>(other))
    {
        return;
    }
    
    if (asteroidSet == 2)
    {
        DestroyActor();
        return;
    }
    for (size_t i = 0; i < 2; i++)
    {
        AAsteroid* newAst = GameManager::GetInstance().GetActorManager()->CreateNewActor<AAsteroid>("Asteroid", "Assets/Asteroid.png", GetPosition());

        newAst->SetAsteroidSize(asteroidSet + 1);
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
        std::cout << "Scale is " << std::to_string(newAst->asteroidSet) << std::endl;

        //Flick in different direction
        sf::Vector2f vector = sf::Vector2f(moveVector.x + Random::RandomFloat(-leftMovement, rightMovement), moveVector.y + Random::RandomFloat(-leftMovement, rightMovement));
        newAst->SetAsteroidVector(vector);

        DestroyActor();
    }
}

void AAsteroid::WrapCheck()
{
    sf::Vector2f PlayerPos = GetPosition();
    
    //NON WRAPPING DELETION
    // if (PlayerPos.x > GameManager::GetInstance().GetWindowSize().x || PlayerPos.x < -100 ||
    //     PlayerPos.y > GameManager::GetInstance().GetWindowSize().y || PlayerPos.y < -100)
    // {
    //     DestroyActor();
    //     std::cout << "Destroyed Actor because it was out of bounds" << std::endl;
    // }
    if (PlayerPos.x > GameManager::GetInstance().GetWindowSize().x)
    {
        PlayerPos.x = 0;
    }
    //If Player x is less than 0
    else if (PlayerPos.x < 0)
    {
        PlayerPos.x = GameManager::GetInstance().GetWindowSize().x;
    }

    //If Player is higher than WindowSize
    if (PlayerPos.y > GameManager::GetInstance().GetWindowSize().y)
    {
        PlayerPos.y = 0;
    }
    //If Player is lower than 0
    else if (PlayerPos.y < 0)
    {
        PlayerPos.y = GameManager::GetInstance().GetWindowSize().y;
    }
    
    SetPosition(PlayerPos);
}
