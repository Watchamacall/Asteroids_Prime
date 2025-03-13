#include "Player.h"
#include "Asteroid.h"
APlayer::APlayer(const std::string& textureLocation, const std::string& actorName) : Actor(textureLocation, actorName)
{
	controller = std::make_unique<PlayerController>(this);
}

void APlayer::FrameCall(float dt)
{
	Actor::FrameCall(dt);
	
	controller->FrameCall(dt);
}

void APlayer::OnCollisionStarted(Actor* other)
{
	if (!other)
	{
		return;
	}
	
	if (dynamic_cast<AAsteroid*>(other))
	{
		std::cout << "Asteroid has hit player" << std::endl;
	}
}
