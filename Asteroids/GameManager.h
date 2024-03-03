#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "GameArea.cpp"

class Actor;
class Player;
class Asteroid;
class Widget;
class StartGameWidget;
class EndGameWidget;

#define _USE_MATH_DEFINES
#include <math.h>

class GameManager
{
#pragma region Variables
public:
	///<summary>
	///The Render Window
	/// </summary>
	sf::RenderWindow* Window;
	/// <summary>
	/// Game Clock
	/// </summary>
	sf::Clock* GameClock;
	/// <summary>
	/// Delta Time
	/// </summary>
	sf::Time dt;

public:
	/// <summary>
	/// The Current aspect of the game
	/// </summary>
	GameArea CurrentGame = GameArea::StartGame;
private:
	/// <summary>
	/// The maximum lives the Player has
	/// </summary>
	const int MaxLives = 3;
	/// <summary>
	/// The current lives the Player has
	/// </summary>
	int CurLives = 3;
	/// <summary>
	/// The maximum number of new Asteroids that can be on the screen at one given time
	/// </summary>
	const int MaxAsteroids = 1000;
	/// <summary>
	///The Current Score the Player has
	/// </summary>
	int CurScore;
	///<summary>
	///The Vector holding all pointers to the new Asteroids
	///</summary>
	std::vector<Asteroid*> SpawnedAsteroids = std::vector<Asteroid*>();
	/// <summary>
	/// The pointer to the Player
	/// </summary>
	Player* PlayerPtr;
	/// <summary>
	/// The pointer to the Widget
	/// </summary>
	Widget* WidgetPtr;
public:

	/// <summary>
	/// The Pointer to the StartGameWidget
	/// </summary>
	StartGameWidget* StartGameWidgetPtr;

	/// <summary>
	/// The Pointer to the StartGameWidget
	/// </summary>
	EndGameWidget* EndGameWidgetPtr;
private:
	sf::Vector2f ButtonPositionOffset = sf::Vector2f(400.f, 600.f);
	sf::Vector2f GameNamePositionOffset = sf::Vector2f(400.f, 200.f);
	/// <summary>
	/// How long it takes for a new Asteroid to spawn in (in seconds)
	/// </summary>
	const float AsteroidSpawnTime = 10.f;
	/// <summary>
	/// The angle to the left that the Asteroid can turn once they spawn in
	/// </summary>
	const float MinAngle = 45.f;
	/// <summary>
	/// The angle to the right that the Asteroid can turn once they spawn in
	/// </summary>
	const float MaxAngle = 45.f;
	/// <summary>
	/// The vector holding a pointer to all Actors which are spawned in
	/// </summary>
	std::vector<Actor*> SpawnedActors;
	/// <summary>
	/// The bounding box for the Asteroids to spawn in
	/// </summary>
	std::vector<sf::Vector2f> BoundingBox;
	/// <summary>
	/// The vectors of Actors which are on their way to being destroyed
	/// </summary>
	std::vector<Actor*> DestructionQueue;
	/// <summary>
	/// The time since the last Asteroid spawned
	/// </summary>
	float TimeToSpawn = 0.f;
public:
	/// <summary>
	///Default Constructor, creates the Window with a default size and Name
	/// </summary>
	GameManager();
	/// <summary>
	///Constructor with ability to choose the Window Size and Name
	/// </summary>
	GameManager(const char* WindowName, const sf::Vector2f WindowSize);
	/// <summary>
	///Default Deconstructor
	/// </summary>
	~GameManager();

	/// <summary>
	///Converts the inputted float to a sf::Vector2f
	/// </summary>
	static sf::Vector2f DegreesToVector2f(float Degrees);

	/// <summary>
	/// Returns a random number based on the Min and Max Range inputted
	/// </summary>
	/// <param name="MinRange"> The Min Range that can be returned </param>
	/// <param name="MaxRange"> The Max Range that can be returned </param>
	/// <param name="MakeMinNegative"> Should the Min Range be changed to a negative?</param>
	/// <returns> The Randomised Number </returns>
	static int RandomRange(int MinRange, int MaxRange, bool MakeMinNegative = false);

	/// <summary>
	/// Finds the angle needed to return to the center of the screen based on the ActorCoords
	/// </summary>
	/// <param name="ActorCoords"> The Position of the Actor</param>
	/// <returns>The angle needed to go towards the center of the screen</returns>
	float FindAngleToCenterScreen(sf::Vector2f ActorCoords);

	/// <summary>
	/// Returns a Pointer to the Player
	/// </summary>
	/// <returns> A Pointer to the Player</returns>
	Player* GetPlayer();

	/// <summary>
	/// Called each frame
	/// </summary>
	void RunTime();

	/// <summary>
	/// Called if the Game is in the GameStart State
	/// </summary>
	void GameAtStart();

	/// <summary>
	/// Called if the game is in the Playing State
	/// </summary>
	void GameRunning();

	/// <summary>
	/// Called if the Game is in the GameEnd State
	/// </summary>
	void GameAtEnd();

	/// <summary>
	///Removes the inputted Actor from the game
	/// </summary>
	/// <param name="ActorToDelete"> Pointer to the Actor wanting to be deleted</param>
	void Remove(Actor* ActorToDelete);
	
	/// <summary>
	/// Starts the Game
	/// </summary>
	void StartGame();

	/// <summary>
	/// Ends the game
	/// </summary>
	void EndGame();

	/// <summary>
	/// Spawns in a large Asteroid at the given Location
	/// </summary>
	/// <param name="Location"> The Position to spawn the Asteroid at</param>
	void SpawnLargeAsteroid(sf::Vector2f Location);
	
	/// <summary>
	/// Adds ScoreToAdd to the Current Score
	/// </summary>
	/// <param name="ScoreToAdd>The Score to be added</param>
	void AddScore(int ScoreToAdd);

	/// <summary>
	/// Resets the Player and loses a life
	/// </summary>
	void ResetPlayer();

	/// <summary>
	/// Starts the Player's Invulnerability timer
	/// </summary>
	void StartPlayerInvulnerability();

	/// <summary>
	/// Spawns in type T to the given Location and Rotation
	/// </summary>
	/// <param="Location">The Location to spawn in T</param>
	/// <param="Rotation">The Rotation to spawn in T to</param>
	/// <returns>The instanciated T</returns>
	template <typename T>
	T* Spawn(sf::Vector2f Location = sf::Vector2f(0.f, 0.f), float Rotation = 0.f);

private:
	/// <summary>
	/// Goes through the destruction queue and deletes them from the game
	/// </summary>
	void DestroyQueue();
};


