#pragma once
#include "GameState.h"
#include "Player.h"

class AsteroidMSpawner;

class MainGameState : public GameState
{
protected:
    APlayer* player;
public:
    std::unique_ptr<AsteroidMSpawner> aMasterSpawner;

public:
    MainGameState(GameManager* gameManager) : GameState(gameManager) 
    { 
    };

    virtual void Enter() override;
    void FrameCall(float dt) override;
    void Draw(sf::RenderWindow* window) override;
};