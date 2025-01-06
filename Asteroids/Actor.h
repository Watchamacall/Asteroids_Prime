#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>

class GameManager;

class Actor
{
public:

protected:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::FloatRect collider;
	std::string name;
public:
	/*
	* IMPROVAL:
	* Change the constructor to have a basic shape
	*/
	Actor(const std::string& actorName, const std::string& textureLocation);
	virtual ~Actor() = default;

	/*
	*  Called every frame
	*/
	virtual void FrameCall(float dt);
	
	sf::Texture const GetTexture() { return texture; }
	sf::Sprite const GetSprite() { return sprite; }
	sf::FloatRect const GetCollider() { return collider; }
	std::string const GetName() { return name; }
	
	sf::Vector2f const GetPosition() { return sprite.getPosition(); }

	sf::Vector2f const GetForwardVector();
	
	sf::Vector2f const GetRightVector();


	void SetTexture(std::string textureLocation);
	void SetTexture(sf::Image image);

	/*
	* Sets the position of the Actor
	*/
	void SetPosition(float x, float y);
	/*
	* Sets the position of the Actor
	*/
	void SetPosition(const sf::Vector2f& newPosition);

	void Translate(float x, float y);

	void Translate(const sf::Vector2f& moveVector);
	/*
	* Sets the rotation of the Actor
 	*/
	void SetRotation(float angle);

	/*
	* Rotates the Actor around angle
	*/
	void Rotate(float angle);
};

