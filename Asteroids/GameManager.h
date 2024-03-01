#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Asteroid.h"
#include "Player.h"
#include "Actor.h"

#define _USE_MATH_DEFINES
#include <math.h>

class GameManager
{
#pragma region Variables
public:
	sf::RenderWindow* Window;
	sf::Clock* GameClock;
	sf::Time dt;

private:
	//The Maximum Lives the Player has
	const int MaxLives = 3;
	//The current Lives the Player has
	int CurLives = 3;
	//The maximum number of new Asteroids that can be on screen at one given time
	const int MaxAsteroids = 10;
	//The Current Score the Player has
	int CurScore;
	//The Vector holding all pointer to the new Asteroids
	std::vector<Asteroid*> SpawnedAsteroids = std::vector<Asteroid*>();
	//The pointer to the Player
	Player* PlayerPtr;
	//The time that passes when a new Asteroid spawns in (in seconds)
	float AsteroidSpawnTime = 10.f;
	//The time the Player has for invulnerability after spawning back in (in seconds)
	float InvulnerabilityFrames = 3.f;
	//The Vector holding all Spawned Actors in the screen
	std::vector<Actor*> SpawnedActors;
	//The Bounding Box area for Spawning Asteroids
	std::vector<sf::Vector2f> BoundingBox;

public:
	//Default Constructor, creates the Window with a default size and Name
	GameManager();
	//Constructor with ability to choose the Window Size and Name
	GameManager(const char* WindowName, const sf::Vector2f WindowSize);
	//Default Deconstructor
	~GameManager();

	//Converts the inputted float to a sf::Vector2f
	static sf::Vector2f DegreesToVector2f(float Degrees);

	static int RandomRange(int MinRange, int MaxRange, bool MakeMinNegative = false);

	float FindAngleToCenterScreen(sf::Vector2f ActorCoords);

	//Returns the Player
	Player* GetPlayer();
	//Called each frame
	void RunTime();

	//Removes the inputted Actor from the game
	void Remove(Actor* ActorToDelete);
	//Starts the Game
	void StartGame();
	//Ends the Game
	void EndGame();
	//Spawns in an Asteroid at the given Location and Direction Vector
	void SpawnLargeAsteroid(sf::Vector2f Location);
	void AddScore(int ScoreToAdd);

	void ResetPlayer();
	void StartPlayerInvulnerability();

	template <typename T>
	T* Spawn(sf::Vector2f Location = sf::Vector2f(0.f, 0.f), float Rotation = 0.f);
};


