#pragma once
#include "GameState.h"

/*
 * Include a player which has a Player Controller consisting of Space for Changing States to Playing; Esc for Closing gameWindow
*/
class MainMenuGameState : public GameState
{
public:
    MainMenuGameState(GameManager* gameManager) : GameState(gameManager) 
    {

    };

    void FrameCall(float dt) override;
    void Draw(sf::RenderWindow* window) override;
};