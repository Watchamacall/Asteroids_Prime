#include "GameOverGameState.h"
#include "MenuActor.h"

GameOverGameState::GameOverGameState(GameManager *gameManager) : GameState(gameManager)
{
}

void GameOverGameState::Enter()
{
    GameState::Enter();

    if (font.loadFromFile(fontFileLocation))
    {
        gameOverText.setFont(font);
        instructionalText.setFont(font);
    }
    gameOverText.setString(gameOverString);
    instructionalText.setString(instructionalString);

    gameOverText.setCharacterSize(fontSize);
    instructionalText.setCharacterSize(fontSize);

    gameOverText.setFillColor(fontColour);
    instructionalText.setFillColor(fontColour);

    sf::Vector2u screenSize = gameManager->GetWindowSize();
    sf::Vector2u middleScreen = sf::Vector2u(screenSize.x / 2, screenSize.y / 2);
    sf::FloatRect gameOverBounds = gameOverText.getGlobalBounds();
    sf::Vector2f gameOverTextCenter = sf::Vector2f(gameOverBounds.left + gameOverBounds.width / 2, gameOverBounds.top + gameOverBounds.height / 2);

    sf::FloatRect instructionalBounds = instructionalText.getGlobalBounds();
    sf::Vector2f instructionalTextCenter = sf::Vector2f(instructionalBounds.left + instructionalBounds.width / 2, instructionalBounds.top + instructionalBounds.height / 2);

    gameOverText.setPosition(sf::Vector2f(middleScreen.x - gameOverTextCenter.x + gameOverTextOffset.x, middleScreen.y - gameOverTextCenter.y + gameOverTextOffset.y));
    instructionalText.setPosition(sf::Vector2f(middleScreen.x - instructionalTextCenter.x + instructionalTextOffset.x, middleScreen.y - instructionalTextCenter.y + instructionalTextOffset.y));

    menuActor = actorManager->CreateNewActor<AMenuActor>("Menu", "No");
}

void GameOverGameState::FrameCall(float dt)
{
    GameState::FrameCall(dt);
}

void GameOverGameState::Draw(sf::RenderWindow *window)
{
    GameState::Draw(window);

    window->draw(gameOverText);
    window->draw(instructionalText);
}
