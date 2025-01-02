#pragma once
#include "Actor.h"
#include "PlayerController.h"
class APlayer :
    public Actor
{

public:
    APlayer(const std::string& textureLocation, const std::string& actorName) : Actor(textureLocation, actorName) {};
    PlayerController controller;

    void Move(sf::Vector2f newPosition);
};

