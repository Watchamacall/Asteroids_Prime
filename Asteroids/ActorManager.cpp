#include "ActorManager.h"
#include <type_traits>
#include "GameManager.h"

ActorManager::ActorManager()
{

}

bool ActorManager::destroyActor(const std::string actorName)
{
    auto remActor = std::find_if(allActors.begin(), allActors.end(), [&](const auto& actor) 
    {
        return actor.get() ->GetName() == actorName;
    });

    if (remActor->get() != nullptr)
    {
        allActors.erase(remActor);
        return true;
    }
    
    return false;
}

void ActorManager::DrawActors(sf::RenderWindow* drawingWindow)
{
    for (auto& sActor : allActors)
    {
        drawingWindow->draw(sActor->GetSprite());
    }
}

bool ActorManager::NameExists(std::string name)
{
    for (auto& sActor : allActors)
    {   
        if (sActor->GetName() == name)
        {
            return true;
        }
    }
    return false;
}

void ActorManager::FrameCall(float dt)
{
    for (auto& singActor : allActors)
    {
        if (singActor.get() != nullptr)
        {
            std::cout << "Actor Called: " << singActor->GetName() << std::endl;
            singActor->FrameCall(dt);
        }
    }
}
