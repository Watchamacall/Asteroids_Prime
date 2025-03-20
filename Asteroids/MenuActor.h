#pragma once
#include "Actor.h"
#include "MenuController.h"

class UIManager;

class AMenuActor : public Actor
{
    
public:
    AMenuActor(const std::string& actorName, const std::string& textureLocation);
    
    virtual void FrameCall(float dt) override;
    
protected:

    MenuController* controller;

    UIManager* uiManager;
};

