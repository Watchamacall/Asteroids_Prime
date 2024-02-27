#include "GameManager.h"

GameManager::GameManager()
{
	Window = new sf::RenderWindow(sf::VideoMode(800, 800), "LHG Code Exercise");
	GameClock = new sf::Clock();
}

GameManager::~GameManager()
{
	delete PlayerPtr;
	for (auto Asteroid : SpawnedAsteroids)
	{
		delete Asteroid;
	}

	delete GameClock;
	delete Window;
}

sf::Vector2f GameManager::DegreesToVector2f(float Degrees)
{
	float Radians = Degrees * ( M_PI / 180.0);

	// Calculate the x and y values using the math of maths
	float x = std::cos(Radians);
	float y = std::sin(Radians);

	return sf::Vector2f(x, y);
}

Player* GameManager::GetPlayer()
{
	return PlayerPtr;
}

void GameManager::StartGame()
{


	if (!PlayerPtr)
	{
		PlayerPtr = new Player(this);
	}
}

void GameManager::EndGame()
{
}

void GameManager::SpawnAsteroid(sf::Vector2f Location, sf::Vector2f Direction)
{
}
