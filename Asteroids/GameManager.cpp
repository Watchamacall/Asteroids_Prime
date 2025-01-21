#include "GameManager.h"
#include "Player.h"
#include "Asteroid.h"

std::unique_ptr<GameManager> GameManager::instance = nullptr;

GameManager::GameManager(const int windowWidth, const int windowHeight, std::string windowTitle)
{
    gameWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(windowWidth, windowHeight), windowTitle);

    actorManager = std::make_unique<ActorManager>();

    kHandle = std::make_unique<KeyboardHandle>();

}

void GameManager::InitialiseGame()
{
    APlayer* player = actorManager->CreateNewActor<APlayer>("Player", "Assets/Ship.png");

    //Start player in middle of screen
    sf::Vector2u windowSize = gameWindow->getSize();
    player->SetPosition(sf::Vector2f(windowSize.x / 2, windowSize.y / 2));
    
    //TESTING ASTEROID
    AAsteroid* Asteroid = actorManager->CreateNewActor<AAsteroid>("Asteroid", "Assets/Asteroid.png");

    while (gameWindow->isOpen())
    {
        sf::Event event;
        while (gameWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                gameWindow->close();
            }
        }

        kHandle->CheckInputs();

        dt = deltaClock.restart().asSeconds(); //Delta Time

        actorManager->FrameCall(dt);
            
        // Reset the window
        gameWindow->clear();

        // Asteroid spins in the center of the screen
        Asteroid->SetPosition(400, 400);
        float Rotation = 90.0f;
        Asteroid->Rotate(Rotation * GetDeltaTime());
        gameWindow->draw(Asteroid->GetSprite());

        actorManager->DrawActors(gameWindow.get());

        gameWindow->display();
    }
    
}
