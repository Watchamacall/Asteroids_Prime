#pragma once
#include <SFML/Graphics.hpp>

class GameManager;

class Widget
{
public:
	/// <summary>
	/// The Text object holding the Score
	/// </summary>
	sf::Text Score;
	/// <summary>
	/// The Text object holding the Lives
	/// </summary>
	sf::Text Lives;
	
	/// <summary>
	/// The Offset to place the Score Text Object based on 0,0
	/// </summary>
	sf::Vector2f ScoreTextOffset = sf::Vector2f(100.f, 100.f);
	/// <summary>
	/// The Offset to place the Lives Text Object based on WindowSize
	/// </summary>
	sf::Vector2f LivesTextOffset = sf::Vector2f(-200.f, 100.f);

	/// <summary>
	/// The Font Object
	/// </summary>
	sf::Font font;
private:
	GameManager* Manager;
public:
	/// <summary>
	/// Default Constructor
	/// </summary>
	/// <param name="Manager">The GameManager Instance</param>
	Widget(GameManager* Manager);
	/// <summary>
	/// Overridden Constructor
	/// </summary>
	/// <param name="Manager">The GameManager Instance</param>
	/// <param name="ScoreInitialText">The text to default on the Score Text Object</param>
	/// <param name="LivesInitialText">The text to default on the Lives Text Object</param>
	/// <param name="FontLocation">The path to the Font used for the Text Objects</param>
	Widget(GameManager* Manager, const std::string ScoreInitialText, const std::string LivesInitialText, const char* FontLocation = "Assets/Font/Arial.ttf");
	~Widget();
	
	/// <summary>
	/// Change the Score Text Object's Text Value
	/// </summary>
	/// <param name="NewScore">The New Score to place into the Score Text Object</param>
	void ChangeScore(float NewScore);
	/// <summary>
	/// Change the Lives Text Object's Text Value
	/// </summary>
	/// <param name="NewLives">The New Lives to place into the Lives Text Object</param>
	void ChangeLives(float NewLives);

	/// <summary>
	/// Called once per frame
	/// </summary>
	/// <param name="dt">Delta Time</param>
	virtual void FrameTime(float dt);
};

