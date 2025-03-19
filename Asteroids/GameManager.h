#pragma once
#include "SFML/Graphics.hpp"
#include "Actor.h"
#include "ActorManager.h"
#include "KeyboardHandle.h"
#include "AsteroidMSpawner.h"
#include "GameState.h"
#include "StateManager.h"
#include <memory>

// class AsteroidMSpawner;
class APlayer;

class GameManager
{
private:

	static std::unique_ptr<GameManager> instance;

	/*
	* Create a GameManager with both a Window Size and a custom title
	*/
	GameManager(const int windowWidth, const int windowHeight, std::string windowTitle);

public:

	static GameManager& GetInstance(const int windowWidth = 800, const int windowHeight = 600, std::string windowTitle = "Asteroids Example")
	{
		if (!instance)
		{
			instance = std::unique_ptr<GameManager>(new GameManager(windowWidth, windowHeight, windowTitle));
		}
		
		return *instance;
	}

	//Stop another instance of GameManager from existing
	GameManager(const GameManager&) = delete;
	GameManager operator=(const GameManager&) = delete;

protected:
	sf::Clock gameClock;
	sf::Clock deltaClock;
	std::unique_ptr<sf::RenderWindow> gameWindow;
	std::unique_ptr<StateManager> stateManager;
	float dt;

public:

	/*
	* Returns the current GameState the program is running in
	*/
	GameState* GetCurrentGameState() { return stateManager->GetCurrentState(); }
	/*
	* Returns the Delta Time in Seconds.
	*/
	float GetDeltaTime() { return dt; };

	/*
	* Returns the size of the Game Window
	*/
	sf::Vector2u GetWindowSize() { return gameWindow->getSize(); }
	
	/*
	* Returns the Game Window
	*/
	sf::RenderWindow* GetWindow() const { return gameWindow.get(); }
	
	/*
	* Initialises game runtime
	*/
	void InitialiseGame();
};

