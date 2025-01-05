#pragma once
#include "Actor.h"
#include "PlayerController.h"
class APlayer : public Actor
{
public:
    APlayer(const std::string& actorName, const std::string& textureLocation);
    
    virtual void FrameCall(float dt) override;
    
protected:
    std::unique_ptr<PlayerController> controller;

};

