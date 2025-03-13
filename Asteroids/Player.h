#pragma once
#include "Actor.h"
#include "PlayerController.h"

class AAsteroid;
class APlayer : public Actor
{
    
public:
    APlayer(const std::string& actorName, const std::string& textureLocation);
    
    virtual void FrameCall(float dt) override;

    virtual void OnCollisionStarted(Actor* other) override;
    
protected:
    std::unique_ptr<PlayerController> controller;

};

