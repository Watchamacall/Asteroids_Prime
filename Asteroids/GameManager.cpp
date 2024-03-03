#include "GameManager.h"

#include "Asteroid.h"
#include "Player.h"
#include "Actor.h"
#include "Projectile.h"
#include "Widget.h"
#include "StartGameWidget.h"
#include "EndGameWidget.h"

GameManager::GameManager()
{
	Window = new sf::RenderWindow(sf::VideoMode(800, 800), "LHG Code Exercise");
	GameClock = new sf::Clock();

	CurScore = 0;
	PlayerPtr = nullptr;
	WidgetPtr = nullptr;

	StartGameWidgetPtr = new StartGameWidget(this, ButtonPositionOffset, GameNamePositionOffset);

	EndGameWidgetPtr = new EndGameWidget(this, ButtonPositionOffset, GameNamePositionOffset);

	BoundingBox = { sf::Vector2f(0,0), sf::Vector2f(0,800), sf::Vector2f(800,800), sf::Vector2f(800, 0) };
}

GameManager::GameManager(const char* WindowName, const sf::Vector2f WindowSize)
{
	Window = new sf::RenderWindow(sf::VideoMode(static_cast<int>(WindowSize.x), static_cast<int>(WindowSize.y)), WindowName);
	GameClock = new sf::Clock();

	CurScore = 0;
	PlayerPtr = nullptr;
	WidgetPtr = nullptr;

	StartGameWidgetPtr = new StartGameWidget(this, ButtonPositionOffset, GameNamePositionOffset);

	EndGameWidgetPtr = new EndGameWidget(this, ButtonPositionOffset, GameNamePositionOffset);

	BoundingBox = { sf::Vector2f(0,0), sf::Vector2f(0,WindowSize.y), WindowSize, sf::Vector2f(WindowSize.x,0) };
}

GameManager::~GameManager()
{
	delete PlayerPtr;
	for (auto Act = SpawnedAsteroids.rbegin(); Act != SpawnedAsteroids.rend(); ++Act)
	{
		delete* Act;
	}
	for (auto Act = SpawnedActors.rbegin(); Act != SpawnedActors.rend(); ++Act)
	{
		delete* Act;
	}
	delete GameClock;
	delete Window;
	delete WidgetPtr;
	delete StartGameWidgetPtr;
}

sf::Vector2f GameManager::DegreesToVector2f(float Degrees)
{
	float Radians = (Degrees - 90.f) * ( M_PI / 180.0);

	// Calculate the x and y values using the math of maths
	float x = std::cos(Radians);
	float y = std::sin(Radians);

	return sf::Vector2f(x, y);
}

int GameManager::RandomRange(int MinRange, int MaxRange, bool MakeMinNegative)
{
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
	Window->clear(); //Clear the window ready for the next set
	switch (CurrentGame)
	{
	case GameArea::StartGame:
		GameAtStart();
		break;
	case GameArea::Playing:
		GameRunning();
		break;
	case GameArea::EndGame:
		GameAtEnd();
		break;
	default:
		break;
	}
}
void GameManager::GameAtStart()
{
	StartGameWidgetPtr->FrameTime(dt.asSeconds());
}

void GameManager::GameRunning()
{
	if (CurLives == 0)
	{
		CurrentGame = GameArea::EndGame;
		EndGameWidgetPtr->SetScoreText(CurScore);
	}
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
		WidgetPtr->FrameTime(dt.asSeconds());

		if (DestructionQueue.size() != 0)
		{
			DestroyQueue();
		}
	}

	TimeToSpawn += dt.asSeconds();
	if (TimeToSpawn > AsteroidSpawnTime)
	{

		sf::Vector2f SpawnLocation;
		if (RandomRange(0, 10) < 5)
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
		float AngleChange = RandomRange(MinAngle, MaxAngle, true);

		NewAst->MoveDirection = (MoveVector /*+ AngleChange*/);

		NewAst = nullptr;
		TimeToSpawn = 0;
	}
}

void GameManager::GameAtEnd()
{
	EndGameWidgetPtr->FrameTime(dt.asSeconds());
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
	DestructionQueue.push_back(ActorToDelete);
}

void GameManager::StartGame()
{
	if (!PlayerPtr)
	{
		PlayerPtr = new Player(this);
		SpawnedActors.push_back(PlayerPtr);
	}
	PlayerPtr->Sprite.setPosition(sf::Vector2f(Window->getSize().x * 0.5f, Window->getSize().y * 0.5f));
	
	CurLives = MaxLives;
	CurScore = 0;
	if (!WidgetPtr)
	{
		std::string LivesString = "Lives: ";
		LivesString.append(std::to_string(MaxLives));
		WidgetPtr = new Widget(this, std::string("Score: 0"), LivesString);
	}
	CurrentGame = GameArea::Playing;
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
	WidgetPtr->ChangeScore(CurScore);
}

void GameManager::ResetPlayer()
{
	PlayerPtr->Sprite.setPosition(sf::Vector2f(Window->getSize().x * 0.5f, Window->getSize().y * 0.5f));
	StartPlayerInvulnerability();
	CurLives -= 1;
	WidgetPtr->ChangeLives(CurLives);
}

void GameManager::StartPlayerInvulnerability()
{
	PlayerPtr->IsImmune = true;
}

template<typename T>
inline T* GameManager::Spawn(sf::Vector2f Location, float Rotation)
{
	T* NewActor = new T(this);

	if (!dynamic_cast<Actor*>(NewActor))
	{
		delete NewActor;
		return nullptr;
	}

	static_cast<Actor*>(NewActor)->Sprite.setPosition(Location);
	static_cast<Actor*>(NewActor)->Sprite.setRotation(Rotation);

	if (dynamic_cast<Asteroid*>(NewActor))
	{
		SpawnedAsteroids.push_back(dynamic_cast<Asteroid*>(NewActor));
	}

	SpawnedActors.push_back(NewActor);
	return NewActor;
}

template Asteroid* GameManager::Spawn<Asteroid>(sf::Vector2f Location, float Rotation);
template Projectile* GameManager::Spawn<Projectile>(sf::Vector2f Location, float Rotation);

void GameManager::DestroyQueue()
{

	for (auto Act = DestructionQueue.rbegin(); Act != DestructionQueue.rend(); ++Act)
	{
		//If Asteroid
		if (Asteroid* Delete = dynamic_cast<Asteroid*>(*Act))
		{
			auto Found = std::find(SpawnedAsteroids.begin(), SpawnedAsteroids.end(), Delete);
			if (Found != SpawnedAsteroids.end())
			{
				SpawnedAsteroids.erase(Found);
			}
		}

		auto Found = std::find(SpawnedActors.begin(), SpawnedActors.end(), *Act);
		if (Found != SpawnedActors.end())
		{
			SpawnedActors.erase(Found);
		}

		delete *Act;
	}
	DestructionQueue.clear();
}