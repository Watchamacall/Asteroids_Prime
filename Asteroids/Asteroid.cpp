#include "Asteroid.h"

Asteroid::Asteroid(GameManager* Manager) : Actor(Manager)
{

}

void Asteroid::FrameTime(float dt)
{
	Sprite.move(MoveDirection * (Velocity * dt));
}

void Asteroid::Hit(Actor* Other)
{

}

void Asteroid::Break()
{

}
