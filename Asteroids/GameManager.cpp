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
	for (auto SinActor : SpawnedActors)
	{
		delete SinActor;
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

void GameManager::RunTime()
{
	/*
	* Nested for loop going through each Actor and checking for collision
	*/
	for (size_t i = 0; i < SpawnedActors.size(); i++)
	{
		for (size_t j = i + 1; j < SpawnedActors.size(); j++)
		{
			if (SpawnedActors[i]->CollidedWith(SpawnedActors[j]))
			{
				SpawnedActors[i]->Hit(SpawnedActors[j]);
			}
		}
		SpawnedActors[i]->FrameTime(dt.asSeconds()); //Frametime call
	}
}

void GameManager::Remove(Actor* ActorToDelete)
{
	//If Asteroid
	if (Asteroid* Delete = dynamic_cast<Asteroid*>(ActorToDelete))
	{
		auto Found = std::find(SpawnedAsteroids.begin(), SpawnedAsteroids.end(), Delete);
		if (Found != SpawnedAsteroids.end())
		{
			SpawnedAsteroids.erase(Found);
			delete &Found;
		}
	}

	auto Found = std::find(SpawnedActors.begin(), SpawnedActors.end(), ActorToDelete);
	if (Found != SpawnedActors.end())
	{
		SpawnedActors.erase(Found);
		delete& Found;
	}
}

void GameManager::StartGame()
{
	if (!PlayerPtr)
	{
		PlayerPtr = new Player(this);
		SpawnedActors.push_back(PlayerPtr);
	}

}

void GameManager::EndGame()
{
	//Show your 
}

void GameManager::SpawnAsteroid(sf::Vector2f Location, sf::Vector2f Direction)
{
	if (SpawnedAsteroids.size() > MaxAsteroids)
		return;
	
	Asteroid* NewAst = new Asteroid(this);
	SpawnedAsteroids.push_back(NewAst);

	NewAst->Sprite.setPosition(Location);
	NewAst->MoveDirection = Direction;
}

