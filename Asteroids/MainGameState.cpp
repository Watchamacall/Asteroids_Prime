#include "MainGameState.h"
#include "AsteroidMSpawner.h"

void MainGameState::Enter()
{
    if (!aMasterSpawner)
    {
        aMasterSpawner = std::make_unique<AsteroidMSpawner>();
    }
    
    player = actorManager->CreateNewActor<APlayer>("Player", "Assets/Ship.png");
}

void MainGameState::FrameCall(float dt)
{
    GameState::FrameCall(dt);
    aMasterSpawner->FrameCall(dt);
}

void MainGameState::Draw(sf::RenderWindow *window)
{
    GameState::Draw(window);
}
