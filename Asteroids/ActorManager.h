#pragma once
#include <vector>
#include <memory>
#include "Actor.h"
#include "SFML/Graphics.hpp"
#include <iostream>

class GameManager;

class ActorManager
{  
public:
    ActorManager();

protected:
    std::vector<std::unique_ptr<Actor>> allActors;

public:
    /*
    * Creates an Actor of type T and returns it
    */
	template <typename T> 
    T* CreateNewActor(const std::string& actorName, const std::string& textureLocation)
    {
        static_assert(std::is_base_of<Actor, T>::value, "T must be derived from Actor");

        int nameAddition = 0;
        while (NameExists(actorName + std::to_string(nameAddition)))
        {
            nameAddition += 1;
        }
        
        std::string newActorName = actorName + std::to_string(nameAddition);

        std::cout << "Actor Name: " + newActorName << std::endl;
        
        auto newActor = std::make_unique<T>(newActorName, textureLocation);
        T* returnActor = newActor.get();
        allActors.push_back(std::move(newActor));

        return returnActor;
    }

    /*
    * Destroys Actor based on name
    */
    bool destroyActor(const std::string actorName);
    
    /*
    * Destroys Actor based on the exact Reference
    */ 
    bool destroyActor(Actor& actor)
    {
        return destroyActor(actor.GetName());
    }

    /*
    * Draws all the Actors to the drawingWindow
    */
    void DrawActors(sf::RenderWindow* drawingWindow);

    /*
    * Returns true if name exists in the currently spawned Actors
    */
    bool NameExists(std::string name);

    virtual void FrameCall(float dt);

};