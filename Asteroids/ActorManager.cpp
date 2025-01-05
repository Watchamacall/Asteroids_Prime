#include "ActorManager.h"
#include <type_traits>

bool ActorManager::destroyActor(const char *actorName)
{
    for (auto& sActor : allActors)
    {
        //Pop the array element maybe?0
        if (sActor->GetName() == actorName)
        {
            delete (sActor.release());
            return true;
        }
    }
    
    return false;
}

void ActorManager::FrameCall(float dt)
{
    for (auto& singActor : allActors)
    {
        singActor->FrameCall(dt);
    }
    
}
