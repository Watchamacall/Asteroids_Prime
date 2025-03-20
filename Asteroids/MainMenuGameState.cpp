#include "MainMenuGameState.h"
#include "GameManager.h"
#include "MenuActor.h"
#include "Player.h"


MainMenuGameState::MainMenuGameState(GameManager *gameManager): GameState(gameManager) 
{   
}


void MainMenuGameState::FrameCall(float dt)
{
    GameState::FrameCall(dt);
}

void MainMenuGameState::Enter()
{
    GameState::Enter();

    if (font.loadFromFile(fontFileLocation))
    {
        asteroidText.setFont(font);
        instructionalText.setFont(font);
    }
    else
    {
        std::cout << "Cannot find file" << std::endl;
    }
    
    asteroidText.setString(asteroidString);
    instructionalText.setString(instructionalString);

    asteroidText.setFillColor(fillColour);
    instructionalText.setFillColor(fillColour);

    asteroidText.setCharacterSize(fontSize);
    instructionalText.setCharacterSize(fontSize);

    sf::Vector2u screenSize = gameManager->GetWindowSize();
    sf::Vector2u middleScreen = sf::Vector2u(screenSize.x / 2, screenSize.y / 2);

    
    sf::FloatRect asteroidBounds = asteroidText.getGlobalBounds();
    sf::FloatRect instructionalBounds = instructionalText.getGlobalBounds();
    sf::Vector2f asteroidTextCenter = sf::Vector2f(asteroidBounds.left + asteroidBounds.width / 2, asteroidBounds.top + asteroidBounds.height / 2);
    sf::Vector2f instructionalTextCenter = sf::Vector2f(instructionalBounds.left + instructionalBounds.width / 2, instructionalBounds.top + instructionalBounds.height / 2);

    asteroidText.setPosition(sf::Vector2f(middleScreen.x - asteroidTextCenter.x + asteroidTextOffset.x, middleScreen.y - asteroidTextCenter.y + asteroidTextOffset.y));
    instructionalText.setPosition(sf::Vector2f(middleScreen.x - instructionalTextCenter.x + instructionalTextOffset.x, middleScreen.y - instructionalTextCenter.y + instructionalTextOffset.y));
    
    menuActor = actorManager->CreateNewActor<AMenuActor>("Menu","No");

    actorManager->CreateNewActor<APlayer>("Player", "Assets/Ship.png");
}

void MainMenuGameState::Draw(sf::RenderWindow* window)
{
    GameState::Draw(window);

    window->draw(instructionalText);
    window->draw(asteroidText);
}


