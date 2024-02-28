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
	const int MaxLives = 3;
	int CurLives = 3;
	const int MaxAsteroids = 10;
	int CurScore;
	std::vector<Asteroid*> SpawnedAsteroids = std::vector<Asteroid*>();
	Player* PlayerPtr;
	float AsteroidSpawnTime;
	float InvulnerabilityFrames;

	std::vector<Actor*> SpawnedActors;

public:
	GameManager();
	~GameManager();

	static sf::Vector2f DegreesToVector2f(float Degrees);
	Player* GetPlayer();
	void RunTime();

	void Remove(Actor* ActorToDelete);
private:
	void StartGame();
	void EndGame();
	void SpawnAsteroid(sf::Vector2f Location, sf::Vector2f Direction);
};

