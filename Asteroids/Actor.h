#pragma once
#include <SFML/Graphics.hpp>

class GameManager;

class Actor
{
public:
	const char* TextureLocation;
	sf::Texture Texture;
	sf::Sprite Sprite;
	GameManager* Manager;

public:
	/// <summary>
	/// Default Constructor for Actor
	/// </summary>
	/// <param name="Manager">The Primary GameManager instance</param>
	/// <param name="TextureLoc">The location of the Texture loaded onto this Actor</param>
	Actor(GameManager* Manager, const char* TextureLoc = "");

	/// <summary>
	/// Default Deconstructor
	/// </summary>
	~Actor();

	/// <summary>
	/// Function called each frame of the game
	/// </summary>
	/// <param name="dt">Delta Time</param>
	virtual void FrameTime(float dt);
	/// <summary>
	/// Called when Actor hits another Actor
	/// </summary>
	/// <param name="Other">The Other Actor hit</param>
	virtual void Hit(Actor* Other);

	virtual void Move(float MoveDirection, float MoveSpeed);
	/// <summary>
	/// Returns true if Actor has collided with Other
	/// </summary>
	/// <param name="Other">Actor compared for collision</param>
	/// <returns>true if Other is intersecting with this</returns>
	bool CollidedWith(Actor* Other);
};

