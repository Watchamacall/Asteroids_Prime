#include "GameManager.h"
#include "Player.h"
#include "Asteroid.h"
// #include "AsteroidMSpawner.h"


std::unique_ptr<GameManager> GameManager::instance = nullptr;

GameManager::GameManager(const int windowWidth, const int windowHeight, std::string windowTitle)
{
    gameWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(windowWidth, windowHeight), windowTitle);

    actorManager = std::make_unique<ActorManager>();

    mainMenuKeyboardHandle = std::make_unique<KeyboardHandle>();
    playingKeyboardHandle = std::make_unique<KeyboardHandle>();
    gameOverKeyboardHandle = std::make_unique<KeyboardHandle>();

    aMasterSpawner = std::make_unique<AsteroidMSpawner>();

    mainMenuKeyboardHandle->GetKeyBindings()->CreateNewInput("Start", sf::Keyboard::Space);
    mainMenuKeyboardHandle->GetKeyBindings()->GetInput("Start")->onPressed->AddDelegate([this] { gameState = STATE_PLAYING; });
    mainMenuKeyboardHandle->GetKeyBindings()->CreateNewInput("Quit", sf::Keyboard::Escape);
    mainMenuKeyboardHandle->GetKeyBindings()->GetInput("Quit")->onPressed->AddDelegate([this] { gameWindow->close(); });

    gameOverKeyboardHandle->GetKeyBindings()->CreateNewInput("Restart", sf::Keyboard::Space);
    gameOverKeyboardHandle->GetKeyBindings()->GetInput("Restart")->onPressed->AddDelegate([this] { gameState = STATE_PLAYING; });
    gameOverKeyboardHandle->GetKeyBindings()->CreateNewInput("Quit", sf::Keyboard::Escape);
    gameOverKeyboardHandle->GetKeyBindings()->GetInput("Quit")->onPressed->AddDelegate([this] { gameWindow->close(); });
}

void GameManager::InitialiseGame()
{
    APlayer* player = actorManager->CreateNewActor<APlayer>("Player", "Assets/Ship.png");

    //Start player in middle of screen
    sf::Vector2u windowSize = gameWindow->getSize();
    player->SetPosition(sf::Vector2f(windowSize.x / 2, windowSize.y / 2));

    while (gameWindow->isOpen())
    {
        // Reset the window
        gameWindow->clear();

        sf::Event event;
        while (gameWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                gameWindow->close();
            }
        }

        switch (gameState)
        {
        case STATE_MAIN_MENU:
            HandleMainMenu();
            break;
        case STATE_PLAYING:
            HandlePlaying();
            break;
        case STATE_GAME_OVER:
            HandleGameOver();
            break;
        
        default:
            break;
        }

        gameWindow->display();
    }
}

void GameManager::HandleMainMenu()
{
    mainMenuKeyboardHandle->CheckInputs();
}

void GameManager::HandlePlaying()
{
    playingKeyboardHandle->CheckInputs();

    dt = deltaClock.restart().asSeconds(); //Delta Time

    actorManager->FrameCall(dt);
    aMasterSpawner->FrameCall(dt);

    actorManager->DrawActors(gameWindow.get());

}

void GameManager::HandleGameOver()
{
}
