#pragma once
#include "Actor.h"
#include "PlayerController.h"
class APlayer :
    public Actor
{

public:
    APlayer(const std::string& textureLocation, const std::string& actorName);
    
    virtual void FrameCall(float dt) override;
    
protected:
    std::unique_ptr<PlayerController> controller;

public:
    void Move(sf::Vector2f newPosition);
};

