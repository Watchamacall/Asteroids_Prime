#include "AsteroidMSpawner.h"
#include "Asteroid.h"

AsteroidMSpawner::AsteroidMSpawner()
{
    
}

void AsteroidMSpawner::FrameCall(float dt)
{
    if (timeSinceLastSpawn < spawnsPerSecond)
    {
        timeSinceLastSpawn += dt;
    }
    else
    {
        sf::Vector2u screenSize = GameManager::GetInstance().GetWindowSize();
        sf::Vector2f spawnLocation;
        float rotation;
        //SPAWN ASTEROID IN AT RANDOM POINT ALONG X AND Y AXIS
        if (rand() % 2) //If Even, x axis min or max
        {
            spawnLocation.x = rand() % 2 ? 0 : screenSize.x;
            spawnLocation.y = Random::RandomFloat(0, screenSize.y);
        }
        else //Has to be Odd, y axis min or max
        {
            spawnLocation.y = rand() % 2 ? 0 : screenSize.y;
            spawnLocation.x = Random::RandomFloat(0, screenSize.x);
        }

        float xDifference = (screenSize.x / 2.f) - spawnLocation.x;
        float yDifference = (screenSize.y / 2.f) - spawnLocation.y;

        sf::Vector2f vector = sf::Vector2f(xDifference + Random::RandomFloat(-movementFromCenter, movementFromCenter), yDifference + Random::RandomFloat(-movementFromCenter, movementFromCenter));
        
        AAsteroid* spawnedAsteroid = GameManager::GetInstance().GetActorManager()->CreateNewActor<AAsteroid>("Asteroid", "Assets/Asteroid.png", spawnLocation);

        spawnedAsteroid->SetAsteroidVector(vector);

        timeSinceLastSpawn = 0;
    }
}
