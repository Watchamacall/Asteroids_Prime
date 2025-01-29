#include "AsteroidMSpawner.h"
#include "Asteroid.h"
// #include "GameManager.h"


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
        
        sf::Vector2f centerOfScreen = spawnLocation - sf::Vector2f(screenSize.x / 2.f, screenSize.y / 2.f);
        rotation = std::atan2(centerOfScreen.y, centerOfScreen.x) * (180.0f / M_PI);

        AAsteroid* spawnedAsteroid = GameManager::GetInstance().GetActorManager()->CreateNewActor<AAsteroid>("Asteroid", "Assets/Asteroid.png");

        spawnedAsteroid->SetRotation(rotation);

        timeSinceLastSpawn = 0;
    }
    
}
