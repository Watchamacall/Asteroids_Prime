#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
class GameManager;

class EndGameWidget
{
public:
	/// <summary>
	/// The Text showing the Final Score
	/// </summary>
	sf::Text EndScore;
	/// <summary>
	/// The button pressed to restart the game
	/// </summary>
	Button RestartGame;

private:
	/// <summary>
	/// Pointer to the GameManager
	/// </summary>
	GameManager* Manager;

	/// <summary>
	/// The Position of the EndScore
	/// </summary>
	sf::Vector2f EndScorePosition = sf::Vector2f(300.f,200.f);
	/// <summary>
	/// The Position of the Restart Game Button
	/// </summary>
	sf::Vector2f RestartGamePosition = sf::Vector2f(300.f,400.f);

	/// <summary>
	/// The Size of the RestartGame Button Outline
	/// </summary>
	const sf::Vector2f ButtonSize = sf::Vector2f(200.f, 50.f);
	/// <summary>
	/// The Size of the Button Text in relation to the Outline
	/// </summary>
	const sf::Vector2f ButtonTextSize = sf::Vector2f(50.f, 10.f);
	/// <summary>
	/// The outline of the Button Outline
	/// </summary>
	const sf::Color ButtonOutlineColor = sf::Color::Blue;
	/// <summary>
	/// The Path to the Font to be loaded
	/// </summary>
	const char* FontLocation = "Assets/Font/Arial.ttf";
	/// <summary>
	/// The actual font to load onto the Text
	/// </summary>
	sf::Font Font;

public:
	/// <summary>
	/// Default Constructor
	/// </summary>
	/// <param name="Manager">The GameManager Instance</param>
	/// <param name="ButtonPosition">The Position of the Button</param>
	/// <param name="GameOverPosition">The Position of the GameOver text</param>
	EndGameWidget(GameManager* Manager, const sf::Vector2f ButtonPosition, const sf::Vector2f GameOverPosition);

	/// <summary>
	/// Sets the EndScore Text to the Final Score
	/// </summary>
	/// <param name="FinalScore"></param>
	void SetScoreText(int FinalScore);

	/// <summary>
	/// Called every frame that the CurrentGame is at EndGame
	/// </summary>
	/// <param name="dt">Delta Time</param>
	virtual void FrameTime(float dt);

	/// <summary>
	/// Called when the game has been clicked with the CurrentGame being EndGame
	/// </summary>
	/// <param name="EventType">The Event being called</param>
	void ButtonClickCheck(sf::Event EventType);

};

