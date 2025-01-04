#include "Player.h"

APlayer::APlayer(const std::string& textureLocation, const std::string& actorName) : Actor(textureLocation, actorName)
{

}

void APlayer::Move(sf::Vector2f newPosition)
{
	sprite.setPosition(newPosition);
}
