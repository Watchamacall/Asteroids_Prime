#include "GameManager.h"
#include "Player.h"
#include "Asteroid.h"
// #include "AsteroidMSpawner.h"


std::unique_ptr<GameManager> GameManager::instance = nullptr;

GameManager::GameManager(const int windowWidth, const int windowHeight, std::string windowTitle)
{

    gameWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(windowWidth, windowHeight), windowTitle);
    
    stateManager = std::make_unique<StateManager>();

    // mainMenuKeyboardHandle->GetKeyBindings()->CreateNewInput("Start", sf::Keyboard::Space);
    // mainMenuKeyboardHandle->GetKeyBindings()->GetInput("Start")->onPressed->AddDelegate([this] { gameState = STATE_PLAYING; });
    // mainMenuKeyboardHandle->GetKeyBindings()->CreateNewInput("Quit", sf::Keyboard::Escape);
    // mainMenuKeyboardHandle->GetKeyBindings()->GetInput("Quit")->onPressed->AddDelegate([this] { gameWindow->close(); });

    // gameOverKeyboardHandle->GetKeyBindings()->CreateNewInput("Restart", sf::Keyboard::Space);
    // gameOverKeyboardHandle->GetKeyBindings()->GetInput("Restart")->onPressed->AddDelegate([this] { gameState = STATE_PLAYING; });
    // gameOverKeyboardHandle->GetKeyBindings()->CreateNewInput("Quit", sf::Keyboard::Escape);
    // gameOverKeyboardHandle->GetKeyBindings()->GetInput("Quit")->onPressed->AddDelegate([this] { gameWindow->close(); });
}


void GameManager::InitialiseGame()
{
    while (gameWindow->isOpen())
    {
        // Reset the window
        gameWindow->clear();

        dt = deltaClock.restart().asSeconds(); //Delta Time

        sf::Event event;
        while (gameWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                gameWindow->close();
            }
        }
        stateManager->GetCurrentState()->FrameCall(dt);
        stateManager->GetCurrentState()->Draw(GetWindow());

        gameWindow->display();
    }
}