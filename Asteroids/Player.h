#pragma once
#include "Actor.h"
#include "PlayerController.h"
class APlayer :
    public Actor
{

protected:
    std::shared_ptr<KeyBindings> bindings;

public:
    APlayer(const std::string& textureLocation, const std::string& actorName);
    PlayerController controller;

    void Move(sf::Vector2f newPosition);
};

