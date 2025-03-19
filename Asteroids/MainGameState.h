#pragma once
#include "GameState.h"
#include "Player.h"

class AsteroidMSpawner;

class MainGameState : public GameState
{
public:
    std::unique_ptr<AsteroidMSpawner> aMasterSpawner;
public:
    MainGameState(GameManager* gameManager) : GameState(gameManager) 
    { 
        aMasterSpawner = std::make_unique<AsteroidMSpawner>();
        APlayer* player = actorManager->CreateNewActor<APlayer>("Player", "Assets/Ship.png");
    };

    void FrameCall(float dt) override;
    void Draw(sf::RenderWindow* window) override;
};