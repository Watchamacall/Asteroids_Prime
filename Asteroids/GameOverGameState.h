#pragma once
#include "GameState.h"

class AMenuActor;
/*
 * Include a player which has a Player Controller consisting of Space for Changing States to Playing; Esc for Closing gameWindow
*/
class GameOverGameState : public GameState
{
protected:
    sf::Text gameOverText;
    sf::Text instructionalText;

    std::string gameOverString = "Game Over!";
    std::string score = "";
    std::string instructionalString = "Press 'Space' to restart\nPress 'Q' to Exit";
    
    sf::Font font;
    std::string fontFileLocation = "Assets/arial.ttf";

    sf::Color fontColour = sf::Color::White;
    int fontSize = 24;

    sf::Vector2f gameOverTextOffset = sf::Vector2f(0,-100);
    sf::Vector2f instructionalTextOffset = sf::Vector2f(0,100);

    AMenuActor* menuActor;
public:
    GameOverGameState(GameManager* gameManager);

public:
    virtual void Enter() override;
    void FrameCall(float dt) override;
    void Draw(sf::RenderWindow* window) override;

    void SetScore(int endScore) { score = "Score: " + std::to_string(endScore); };

};