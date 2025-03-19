#pragma once
#include <SFML/Graphics.hpp>
#include "VoidDelegate.h"
#include <memory>
#include "KeyboardHandle.h"
#include "ActorManager.h"

class GameManager; // Forward declaration

class GameState {

public:
    GameManager* gameManager;
    std::unique_ptr<Delegate<void,void>> onEnter;
    std::unique_ptr<Delegate<void,void>> onExit;

    std::unique_ptr<ActorManager> actorManager;
    
public:
    GameState(GameManager* gameManager) : gameManager(gameManager) 
    { 
        onEnter = std::make_unique<Delegate<void,void>>(); 
        onExit = std::make_unique<Delegate<void,void>>(); 
        actorManager = std::make_unique<ActorManager>(); 
    };

    virtual ~GameState() = default;

    // Called when the state is entered
    virtual void Enter() { onEnter->Execute(); };

    // Called every frame to update the state
    virtual void FrameCall(float dt) { actorManager->FrameCall(dt); };

    // Called every frame to render the state
    virtual void Draw(sf::RenderWindow* window) { actorManager->DrawActors(window); };

    // Called when the state is exited
    virtual void Exit() 
    { 
        onExit->Execute();
        // Clear all actors from the actor manager when departing from the state
        actorManager->ClearActors();  
    };

    ActorManager* GetActorManager() { return actorManager.get(); }
};