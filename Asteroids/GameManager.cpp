#include "GameManager.h"
#include "Player.h"
#include "Asteroid.h"


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
    
    AAsteroid* Asteroid = actorManager->CreateNewActor<AAsteroid>("Asteroid", "Assets/Asteroid.png");

    while (gameWindow->isOpen())
    {
        deltaClock.restart(); //Delta Time

        sf::Event event;

        //Frame Time Check
        if (gameClock.getElapsedTime().asSeconds() >= 1.f)
        {
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
        }
        else
        {
            while (gameWindow->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    gameWindow->close();
            }
        }
        
        // Reset the window
        gameWindow->clear();

        //GAME LOGIC THINGS HERE

        sf::Vector2f MousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*gameWindow));

        player->SetPosition(MousePosition);
        
        gameWindow->draw(player->GetSprite());

        // Asteroid spins in the center of the screen
        Asteroid->SetPosition(400, 400);
        float Rotation = 90.0f;
        Asteroid->Rotate(Rotation * deltaClock.getElapsedTime().asSeconds());
        gameWindow->draw(Asteroid->GetSprite());

        gameWindow->display();
    }
    
}
