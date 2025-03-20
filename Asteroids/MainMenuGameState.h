#pragma once
#include "GameState.h"

class GameManager;

class AMenuActor;
/*
 * Include a player which has a Player Controller consisting of Space for Changing States to Playing; Esc for Closing gameWindow
*/
class MainMenuGameState : public GameState
{
public:
    MainMenuGameState(GameManager* gameManager);

    sf::Text asteroidText;
    sf::Text instructionalText;

    const std::string asteroidString = "Asteroids";
    const std::string instructionalString = "Press 'Space' to start\nPress 'Q' to exit";


    sf::Font font;
    const std::string fontFileLocation = "Assets/arial.ttf";
    int fontSize = 24;

    sf::Vector2f asteroidTextOffset = sf::Vector2f(0,-100);
    sf::Vector2f instructionalTextOffset = sf::Vector2f(0,100);

    sf::Color fillColour = sf::Color::White;

    AMenuActor* menuActor;

    virtual void Enter() override;
    void FrameCall(float dt) override;
    void Draw(sf::RenderWindow* window) override;
};;