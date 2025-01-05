#pragma once
#include <SFML/Graphics.hpp>

class Actor
{
public:

protected:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::FloatRect collider;
	std::string name;
public:
	Actor(const std::string& textureLocation, const std::string& actorName);
	virtual ~Actor() = default;

	virtual void FrameCall(float dt);
	
	sf::Texture const GetTexture() { return texture; }
	sf::Sprite const GetSprite() { return sprite; }
	sf::FloatRect const GetCollider() { return collider; }
	std::string const GetName() { return name; }
	
	void SetTexture(std::string textureLocation);
	void SetTexture(sf::Image image);
};

