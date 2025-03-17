#pragma once
#include "Actor.h"
#include "GameManager.h"

 class AAsteroid;
 class APlayer;

class AProjectile : public Actor
{
public:
    AProjectile(const std::string& actorName, const std::string& textureLocation, const sf::Vector2f spawnLocation, Actor* owner);

protected:
    sf::Vector2f moveDir;
    float projectileSpeed = 550.f;
public:
    void SendInDirection(sf::Vector2f movementDirection);

    virtual void FrameCall(float dt) override;

    virtual void OnCollisionStarted(Actor* other) override;
};