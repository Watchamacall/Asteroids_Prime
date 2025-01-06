#include "GameManager.h"
#include "Player.h"
#include "Asteroid.h"

std::unique_ptr<GameManager> GameManager::instance = nullptr;

GameManager::GameManager(const int windowWidth, const int windowHeight, std::string windowTitle)
{
    gameWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(windowWidth, windowHeight), windowTitle);

    actorManager = std::make_unique<ActorManager>();

    kHandle = std::make_unique<KeyboardHandle>();

    frameCallDelegate = std::make_unique<VoidDelegate>();
}

void GameManager::InitialiseGame()
{
    APlayer* player = actorManager->CreateNewActor<APlayer>("Player", "Assets/Ship.png");

    //Start player in middle of screen
    sf::Vector2u windowSize = gameWindow->getSize();
    player->SetPosition(sf::Vector2f(windowSize.x / 2, windowSize.y / 2));
    
    AAsteroid* Asteroid = actorManager->CreateNewActor<AAsteroid>("Asteroid", "Assets/Asteroid.png");

    while (gameWindow->isOpen())
    {
        deltaClock.restart(); //Delta Time
        sf::Event event;
        while (gameWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                gameWindow->close();
            }
            kHandle->CheckInputs(event);
        }

        frameCallDelegate->Execute();

        gameClock.restart(); //Reset our Frame Time
    
        // Reset the window
        gameWindow->clear();

        //GAME LOGIC THINGS HERE
        
        gameWindow->draw(player->GetSprite());

        // Asteroid spins in the center of the screen
        Asteroid->SetPosition(400, 400);
        float Rotation = 90.0f;
        Asteroid->Rotate(Rotation * GetDeltaTime());
        gameWindow->draw(Asteroid->GetSprite());

        gameWindow->display();
    }
    
}
