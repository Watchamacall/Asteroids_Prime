#include "PlayerLives.h"
#include "Player.h"
#include "Component.h"

void PlayerLives::TakeDamage()
{
    currentLives -= 1;

    if (currentLives < 0)
    {
        noLivesLeft->Execute();
    }
    else
    {
        damageTaken->Execute(currentLives);
        //Reset the players
        owner->SetPosition(GameManager::GetInstance().GetWindowSize().x / 2, GameManager::GetInstance().GetWindowSize().y / 2);
        isInvincible = true;
        owner->SetCollision(false);
    }
    
}

void PlayerLives::FrameCall(float dt)
{
    if (isInvincible && currentInvincibilityTime < invincibilityTime)
    {
        currentInvincibilityTime += dt;

        // Calculate alpha using sine function
        float alpha = (sin(currentInvincibilityTime * invincibilityBlinkRate * 2 * M_PI) + 1) / 2 * 255; // Map sin output (-1 to 1) to (0 to 255)

        sf::Color newColor = owner->GetColour();
        newColor.a = alpha; // Set alpha value
        owner->SetColour(newColor);
    }
    else
    {
        isInvincible = false;
        currentInvincibilityTime = 0.f;
        owner->SetCollision(true);

        // Reset color to fully visible
        sf::Color newColor = owner->GetColour();
        newColor.a = 255;
        owner->SetColour(newColor);
    }
}
