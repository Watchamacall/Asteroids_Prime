#include "MenuActor.h"

AMenuActor::AMenuActor(const std::string &actorName, const std::string &textureLocation) : Actor(actorName, textureLocation)
{
    controller = AddComponent<MenuController>();
}

void AMenuActor::FrameCall(float dt)
{
    Actor::FrameCall(dt);
}
