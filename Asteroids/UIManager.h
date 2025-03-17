#pragma once
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Component.h"

class APlayer;
class PlayerLives;
class PlayerScore;
class GameManager;

class UIManager : public Component
{
public:
    UIManager(Actor* owner);

    virtual void FrameCall(float dt) override;

protected:
    APlayer* owner;
    
    sf::Font font;
    sf::Text score = sf::Text();
    sf::Vector2f scorePosition = sf::Vector2f(200, 30);

    sf::Text lives = sf::Text();
    sf::Vector2f livesPosition = sf::Vector2f(100, 30);

    std::string fontLocation = "Assets/arial.ttf";
    sf::Color fontColor = sf::Color::White;
    int fontSize = 24;

public:
    void ScoreChanged(int newScore);

    void LivesChanged(int newLives);
};