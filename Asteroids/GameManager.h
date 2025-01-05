#pragma once
#include "SFML/Graphics.hpp"
#include "Actor.h"
#include "ActorManager.h"
#include "AsteroidMSpawner.h"
#include "KeyboardHandle.h"
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
	* Create a GameManager with both a Window Size and a custom title
	*/
	GameManager(const int windowWidth, const int windowHeight, std::string windowTitle);

	static GameManager& GetInstance()
	{
		static GameManager instance;
		return instance;
	}

	GameManager(const GameManager&) = delete;

protected:
	sf::Clock gameClock;
	sf::Clock deltaClock;
	std::unique_ptr<sf::RenderWindow> gameWindow;
	GameState gameState;
	float dt;

	std::unique_ptr<ActorManager> actorManager;
	std::unique_ptr<AsteroidMSpawner> aMasterSpawner;
	std::unique_ptr<KeyboardHandle> kHandle;

	std::unique_ptr<VoidDelegate> frameCallDelegate;

public:
	/*
	* Returns the Actor Manager
	*/
	const ActorManager* GetActorManager() { return actorManager.get(); }

	/*
	* Returns the keybindings associated with the KeyboardHandle
	*/
	KeyBindings* GetKeybindings() { return kHandle->GetKeyBindings(); }
	
	/*
	* Returns the FrameCallDelegate
	*/
	VoidDelegate* GetFrameCallDelegate() { return frameCallDelegate.get(); }
	
	/*
	* Returns the Delta Time in Seconds.
	*/
	float GetDeltaTime() { return deltaClock.getElapsedTime().asSeconds(); };

	/*
	* Initialises game runtime
	*/
	void InitialiseGame();
};

