#include "VoidDelegate.h"
#include <functional>
#include <memory>
#include "Component.h"

class APlayer;

class PlayerLives : public Component
{
public:
    PlayerLives(Actor* owner) : Component(owner)
    {
        damageTaken = std::make_unique<Delegate<void, int>>();

        noLivesLeft = std::make_unique<Delegate<void, void>>();

        currentLives = maxLives;
    }

public:
    //Executes when damage has been taken
    std::unique_ptr<Delegate<void, int>> damageTaken;

    //Executes when the currentLives <= 0
    std::unique_ptr<Delegate<void, void>> noLivesLeft;

    int maxLives = 3;
    float currentLives;

public:
    void TakeDamage();
};