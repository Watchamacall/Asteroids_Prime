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

protected:
    /*
    * The maximum amount of lives the player can have
    */
    int maxLives = 3;
    /*
    * The current amount of lives the player has
    */
    float currentLives;

    /*
    * The time the player is invincible after taking damage
    */
    float invincibilityTime = 2.f;
    /*
    * The current time the player has been invincible
    */
    float currentInvincibilityTime = 0.f;
    /*
    * Whether the player is invincible or not
    */
    bool isInvincible = false;
    /*
    * The rate at which the player blinks when invincible
    */
    int invincibilityBlinkRate = 5;
public:
    /*
    * Called when the player takes damage
    */
    void TakeDamage();
    virtual void FrameCall(float dt) override;
};