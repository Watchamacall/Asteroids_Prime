#include "MainGameState.h"
#include "AsteroidMSpawner.h"

void MainGameState::FrameCall(float dt)
{
    GameState::FrameCall(dt);
    aMasterSpawner->FrameCall(dt);
}

void MainGameState::Draw(sf::RenderWindow *window)
{
    GameState::Draw(window);
}
