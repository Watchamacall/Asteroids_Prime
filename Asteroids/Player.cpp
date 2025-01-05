#include "Player.h"

APlayer::APlayer(const std::string& textureLocation, const std::string& actorName) : Actor(textureLocation, actorName)
{
	controller = std::make_unique<PlayerController>();
}

void APlayer::FrameCall(float dt)
{
	controller->FrameCall(dt);
}
