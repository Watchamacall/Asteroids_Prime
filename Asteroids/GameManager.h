#pragma once
#include "SFML/Graphics.hpp"
#include "Actor.h"
#include "ActorManager.h"
#include "KeyboardHandle.h"
#include "AsteroidMSpawner.h"
#include <memory>

enum GameState : int8_t
{
	STATE_MAIN_MENU = 0,
	STATE_PLAYING = 1,
	STATE_GAME_OVER = 2
};

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
	GameState gameState;
	float dt;

	std::unique_ptr<ActorManager> actorManager;
	std::unique_ptr<AsteroidMSpawner> aMasterSpawner;
	
	std::unique_ptr<KeyboardHandle> playingKeyboardHandle;
	std::unique_ptr<KeyboardHandle> mainMenuKeyboardHandle;
	std::unique_ptr<KeyboardHandle> gameOverKeyboardHandle;

public:
	/*
	* const ActorManager
	*/
	const ActorManager* GetActorManager() const { return actorManager.get(); }

	/*
	* non-const ActorManager
	*/
	ActorManager* GetActorManager() { return actorManager.get(); }

	/*
	* Returns the keybindings associated with the KeyboardHandle
	*/
	KeyBindings* GetKeybindings() { return playingKeyboardHandle->GetKeyBindings(); }

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

	virtual void HandleMainMenu();

	virtual void HandlePlaying();

	virtual void HandleGameOver();
};

