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

    std::vector<std::unique_ptr<Actor>> newActors;

public:
    /*
    * Creates an Actor of type T and returns it
    */
	template <typename T, typename... Args>
    T* CreateNewActor(Args&&... args)
    {
        static_assert(std::is_base_of<Actor, T>::value, "T must be derived from Actor");
        
        auto newActor = std::make_unique<T>(std::forward<Args>(args)...);
        Actor* returnActor = newActor.get();

        int numberAddition = GetLowestNumber(returnActor->GetName());
        const std::string newName = returnActor->GetName() + " (" + std::to_string(numberAddition) + ")";
        returnActor->SetName(newName);
        newActors.push_back(std::move(newActor));

        return dynamic_cast<T*>(returnActor);
    }

    /*
    * Destroys Actor based on the pointer
    */ 
    bool destroyActor(Actor* actorToDestroy);

    /*
    * Draws all the Actors to the drawingWindow
    */
    void DrawActors(sf::RenderWindow* drawingWindow);

    /*
    * Returns true if name exists in the currently spawned Actors
    */
    bool NameExists(std::string name);

    int GetLowestNumber(const std::string& name);

    virtual void FrameCall(float dt);

};