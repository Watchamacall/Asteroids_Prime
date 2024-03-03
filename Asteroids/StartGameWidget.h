#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Button.h"
class GameManager;

class StartGameWidget
{
public:
	sf::Text GameName;
	Button StartGameButton;

private:
	GameManager* Manager;

	const sf::Vector2f ButtonSize = sf::Vector2f(200.f, 50.f);
	const char* ButtonText = "Start!";
	const sf::Vector2f ButtonTextSize = sf::Vector2f(50.f, 10.f);
	const sf::Color ButtonOutlineColor = sf::Color::Blue;
	const char* FontLocation = "Assets/Font/Arial.ttf";
	sf::Font Font;

public:

	StartGameWidget(GameManager* Manager, const sf::Vector2f ButtonPosition, const sf::Vector2f GameNamePosition, const char* GameNameText = "Asteroids");

	~StartGameWidget();
	void FrameTime(float dt);
	void ButtonClickCheck(sf::Event EventType);
};

