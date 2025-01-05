#pragma once
#include <vector>
#include <memory>
#include "Actor.h"
class ActorManager
{  
protected:
    std::vector<std::unique_ptr<Actor>> allActors;

public:
    /*
    * Creates an Actor of type T and returns it
    */
	template <typename T> 
    T* CreateNewActor(const char* actorName, const char* textureLocation)
    {
        static_assert(std::is_base_of<Actor, T>::value, "T must be derived from Actor");

        auto newActor = std::make_unique<T>(actorName, textureLocation);
        T* returnActor = newActor.get();
        allActors.push_back(std::move(newActor));

        return returnActor;
    }

    /*
    * Destroys Actor based on name
    */
    bool destroyActor(const char* actorName);
    
    /*
    * Destroys Actor based on the exact Reference
    */
    template <typename T> 
    bool destroyActor(const T& actor)
    {
        return destroyActor(actor.getName());
    }

    virtual void FrameCall(float dt);

};