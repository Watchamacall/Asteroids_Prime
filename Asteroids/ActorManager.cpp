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
    for (size_t i = 0; i < std::size(allActors); i++)
    {
        if (allActors[i].get() != nullptr)
        {
            allActors[i]->FrameCall(dt);
            
            //COLLISION CHECK
            for (size_t j = i+1; j < std::size(allActors); j++)
            {
                //Complete i to j
                allActors[i]->TryCollision(allActors[j].get());

                //If i and j are not destroyed that frame
                if (allActors[i].get() != nullptr && allActors[j].get() != nullptr)
                {
                    //Complete j to i
                    allActors[j]->TryCollision(allActors[i].get());
                }
            }
        }   
    }
}
