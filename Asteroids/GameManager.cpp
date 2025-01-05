#include "GameManager.h"
#include "Player.h"



GameManager::GameManager(const int windowWidth, const int windowHeight, std::string windowTitle)
{
    gameWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(windowWidth, windowHeight), windowTitle);

    actorManager = std::make_unique<ActorManager>();
}

void GameManager::InitialiseGame()
{
    APlayer* player = actorManager->createNewActor<APlayer>("Assets/Ship.png", "Player"); //We lose this pointer once this is over (Not good, but unique_ptr allows for smartness)

    
    sf::Texture AsteroidTexture;

    AsteroidTexture.loadFromFile("Assets/Asteroid.png");

    sf::Sprite Asteroid;
    Asteroid.setTexture(AsteroidTexture);

    while (gameWindow->isOpen())
    {
        // Get the delta time for the game update
        sf::Time dt = gameClock.restart(); //Add a clamped dt for actual frametime
        
        FrameCall();
        
        // Poll for window being closed
        sf::Event event;

        while (gameWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameWindow->close();
        }

        // Reset the window
        gameWindow->clear();

        //GAME LOGIC THINGS HERE

        sf::Vector2f MousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*gameWindow));

        player->Move(MousePosition);
        
        gameWindow->draw(player->GetSprite());

        // Asteroid spins in the center of the screen
        Asteroid.setPosition(400, 400);
        float Rotation = 90.0f;
        Asteroid.rotate(Rotation * dt.asSeconds());
        gameWindow->draw(Asteroid);

        gameWindow->display();
    }
    
}

void GameManager::FrameCall()
{
    actorManager->FrameCall(dt.asSeconds());
}
