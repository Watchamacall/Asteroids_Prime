#include "Asteroid.h"
#include "GameManager.h"

void AAsteroid::FrameCall(float dt)
{
    Actor::FrameCall(dt);
    
    sf::Vector2f movementSpeed = sf::Vector2f(GetForwardVector().x * (asteroidSpeed * dt), GetForwardVector().y * (asteroidSpeed * dt));
    Translate(movementSpeed);
    WrapCheck();
}

void AAsteroid::WrapCheck()
{
    sf::Vector2f PlayerPos = GetPosition();
    //If the Player is over the right hand side
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
