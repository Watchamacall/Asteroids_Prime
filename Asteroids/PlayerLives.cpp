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
    }
    
}
