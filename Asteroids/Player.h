#pragma once
#include "Actor.h"
#include "PlayerController.h"

class AAsteroid;
class UIManager;
class PlayerLives;
class PlayerScore;

class APlayer : public Actor
{
    
public:
    APlayer(const std::string& actorName, const std::string& textureLocation);

    PlayerLives* GetPlayerLives() const { return playerLives; }
    PlayerScore* GetPlayerScore() const { return playerScore; }
    
    virtual void FrameCall(float dt) override;

    virtual void OnCollisionStarted(Actor* other) override;
    
protected:
    PlayerController* controller;

    UIManager* uiManager;

    PlayerLives* playerLives;

    PlayerScore* playerScore;

};

