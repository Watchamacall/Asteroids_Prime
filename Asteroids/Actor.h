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

	std::vector<Actor*> collidingActors;

	bool collisionEnabled = false;
public:

	Actor(const std::string& actorName, const std::string& textureLocation, const sf::Vector2f initialPosition = sf::Vector2f());
	virtual ~Actor() = default;

	/*
	*  Called every frame
	*/
	virtual void FrameCall(float dt);
	
	/*
	* Returns the Texture
	*/
	sf::Texture const GetTexture() { return texture; }
	/*
	* Returns the Sprite
	*/
	sf::Sprite const GetSprite() { return sprite; }
	/*
	* Returns the Collider
	*/
	sf::FloatRect const GetCollider() { return collider; }
	/*
	* Returns the Name of the Actor 
	*/
	std::string const GetName() { return name; }
	/*
	* Returns the current Position of the Actor
	*/
	sf::Vector2f const GetPosition() { return sprite.getPosition(); }
	/*
	* Returns the current Rotation of the Actor
	*/
	float const GetRotation() { return sprite.getRotation(); }
	/*
	* Returns the Vector needed to move the Actor forward
	*/
	sf::Vector2f const GetForwardVector();
	/*
	* Returns the Vector needed to move the Actor to the Right
	*/
	sf::Vector2f const GetRightVector();
	/*
	* Returns whether the collision is Enabled or Disabled
	*/
	bool const IsCollisionEnabled() { return collisionEnabled; }
	/*
	* Sets the collision
	*/
	void SetCollision(const bool newState) { collisionEnabled = newState; }
	/*
	* Sets the texture based on the asset location given
	*/
	void SetTexture(std::string textureLocation);
	/*
	* Sets the texture based on the Image given
	*/
	void SetTexture(sf::Image image);

	/*
	* Sets the position of the Actor
	*/
	void SetPosition(float x, float y);
	/*
	* Sets the position of the Actor
	*/
	void SetPosition(const sf::Vector2f& newPosition);
	/*
	* Translate the Actor by the given x and y coordinate
	*/
	void Translate(float x, float y);
	/*
	* Translate the Actor by the given moveVector
	*/
	void Translate(const sf::Vector2f& moveVector);
	/*
	* Sets the rotation of the Actor
 	*/
	void SetRotation(float angle);

	/*
	* Rotates the Actor around angle
	*/
	void Rotate(float angle);
	/*
	* Sets the size of the Actor
	*/
	void SetScale(float newScale) { sprite.setScale(newScale,newScale); }
	/*
	* Returns true if the OtherActor is intersecting with this Actor
	*/
	bool Intersects(Actor* otherActor);

	/*
	* Trys a collision with this Actor against 'other', deals with starting and ending the collision
	*/
	void TryCollision(Actor* other);

	/*
	* Called when the Actor has intersected with 'other'
	*/
	virtual void OnCollisionStarted(Actor* other);

	/*
	* Called when the Actor has finished intersecting with 'other'
	*/
	virtual void OnCollisionEnded(Actor* other);

	/*
	* Destroys this Actor
	*/
	void DestroyActor();
};

