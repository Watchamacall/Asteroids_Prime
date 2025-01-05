#pragma once
#include "SFML/Graphics.hpp"
#include "Actor.h"
#include "ActorManager.h"
#include <memory>

enum GameState : int8_t
{
	STATE_PAUSED = 0,
	STATE_PLAYING = 1
};

class APlayer;

class GameManager
{
public:

	/*
	* Create a basic GameManager
	*/
	GameManager() : GameManager(800, 600) {};

	/*
	* Create a GameManager with a certain windowSize but default title
	*/
	GameManager(const int windowWidth, const int windowHeight) : GameManager(windowWidth, windowHeight, "Asteroids Example") {};

	/*
	* Create a GameManager with both a Window Size and a custom Title
	*/
	GameManager(const int windowWidth, const int windowHeight, std::string windowTitle);

protected:
	sf::Clock gameClock;
	std::unique_ptr<sf::RenderWindow> gameWindow;
	GameState gameState;
	sf::Time dt;

	std::unique_ptr<ActorManager> actorManager;

public:
	/*
	* Returns the Delta Time in Seconds.
	*/
	float GetDeltaTime() { return dt.asSeconds(); };

	/*
	* Initialises game runtime
	*/
	void InitialiseGame();

	//TEMPORARY TESTING
	void FrameCall();

};

