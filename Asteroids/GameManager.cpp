#include "GameManager.h"

GameManager::GameManager()
{
	Window = new sf::RenderWindow(sf::VideoMode(800, 800), "LHG Code Exercise");
	GameClock = new sf::Clock();

	CurScore = 0;
	PlayerPtr = nullptr;

	BoundingBox = { sf::Vector2f(0,0), sf::Vector2f(0,800), sf::Vector2f(800,800), sf::Vector2f(800, 0) };
}

GameManager::GameManager(const char* WindowName, const sf::Vector2f WindowSize)
{
	Window = new sf::RenderWindow(sf::VideoMode(static_cast<int>(WindowSize.x), static_cast<int>(WindowSize.y)), WindowName);
	GameClock = new sf::Clock();

	CurScore = 0;
	PlayerPtr = nullptr;

	BoundingBox = { sf::Vector2f(0,0), sf::Vector2f(0,WindowSize.y), WindowSize, sf::Vector2f(WindowSize.x,0) };
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

int GameManager::RandomRange(int MinRange, int MaxRange, bool MakeMinNegative = false)
{
	int Range;
	
	MinRange = MakeMinNegative ? -MinRange : MinRange;

	//The Range for the Rand Function
	int Range = MaxRange - MinRange;

	return MinRange + std::rand() % Range;
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
				SpawnedActors[j]->Hit(SpawnedActors[i]);
			}
		}
		SpawnedActors[i]->FrameTime(dt.asSeconds()); //Frametime call
	}

	//Add Asteroid Spawning Logic
	sf::Vector2f SpawnLocation;
	if (RandomRange(0,10) < 5)
	{
		SpawnLocation.x = RandomRange(0, Window->getSize().x);
		SpawnLocation.y = RandomRange(0, 10) < 5 ? 0 : Window->getSize().y;
	}
	else
	{
		SpawnLocation.y = RandomRange(0, Window->getSize().y);
		SpawnLocation.x = RandomRange(0, 10) < 5 ? 0 : Window->getSize().x;
	}
	Asteroid* NewAst = Spawn<Asteroid>(SpawnLocation);

	//Trig to find center of screen based on Spawn Location
	float MoveVector = FindAngleToCenterScreen(SpawnLocation);

	//Random Angle based on MinAngle and MaxAngle 
}

float GameManager::FindAngleToCenterScreen(sf::Vector2f ActorCoords)
{
	sf::Vector2f CenterScreen(Window->getSize().x / 2, Window->getSize().y / 2);
	sf::Vector2f Difference(ActorCoords.x - CenterScreen.x, ActorCoords.y - CenterScreen.y);

	float Angle = std::atan2(Difference.y, Difference.x) * 180.f / M_PI;
	return Angle < 0 ? Angle += 360.f : Angle;
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
		}
	}

	auto Found = std::find(SpawnedActors.begin(), SpawnedActors.end(), ActorToDelete);
	if (Found != SpawnedActors.end())
	{
		SpawnedActors.erase(Found);
	}

	delete& Found;

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
	//Show your score and that jazz
}

void GameManager::SpawnLargeAsteroid(sf::Vector2f Location)
{
	if (SpawnedAsteroids.size() > MaxAsteroids)
		return; 
	
	Asteroid* NewAst = Spawn<Asteroid>(Location);


	//NewAst->MoveDirection = Direction;
}

void GameManager::AddScore(int ScoreToAdd)
{
	CurScore += ScoreToAdd;
}

void GameManager::ResetPlayer()
{
	PlayerPtr->Sprite.setPosition(sf::Vector2f(0.f, 0.f));
	StartPlayerInvulnerability();
}

void GameManager::StartPlayerInvulnerability()
{
}

template<typename T>
inline T* GameManager::Spawn(sf::Vector2f Location, float Rotation)
{
	if (!dynamic_cast<Actor>(T))
	{
		return nullptr;
	}
	T* NewActor = new T(this);

	static_cast<Actor*>(NewActor)->Sprite.setPosition(Location);
	static_cast<Actor*>(NewActor)->Sprite.setRotation(Rotation);

	if (dynamic_cast<Asteroid>(T))
	{
		SpawnedAsteroids.push_back(NewActor);
	}

	SpawnedActors.push_back(NewActor);
	return NewActor;
}
