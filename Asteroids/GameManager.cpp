#include "GameManager.h"
#include "Player.h"
#include "Asteroid.h"
#include "MainMenuGameState.h"
#include "MainGameState.h"
#include "GameOverGameState.h"
// #include "AsteroidMSpawner.h"

std::unique_ptr<GameManager> GameManager::instance = nullptr;

GameManager::GameManager(const int windowWidth, const int windowHeight, std::string windowTitle)
{
    gameWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(windowWidth, windowHeight), windowTitle);

    stateManager = std::make_unique<StateManager>();
}

void GameManager::InitialiseGame()
{
    mainMenuState = stateManager->CreateNewState<MainMenuGameState>(this);
    playingState = stateManager->CreateNewState<MainGameState>(this);
    gameOverState = stateManager->CreateNewState<GameOverGameState>(this);

    stateManager->ChangeState(mainMenuState);

    while (gameWindow->isOpen())
    {
        // Reset the window
        gameWindow->clear();

        dt = deltaClock.restart().asSeconds(); // Delta Time

        sf::Event event;
        while (gameWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                gameWindow->close();
            }
        }
        stateManager->FrameCall(dt);
        stateManager->Draw(GetWindow());

        gameWindow->display();
    }
}