#include "EndGameWidget.h"

#include "GameManager.h"
#include "Button.h"

EndGameWidget::EndGameWidget(GameManager* Manager, const sf::Vector2f ButtonPosition, const sf::Vector2f GameOverPosition)
{
	this->Manager = Manager;
	Font.loadFromFile(FontLocation);
	EndScore.setFont(Font);
	RestartGame = Button(ButtonSize, ButtonPosition, ButtonTextSize, "Restart", ButtonOutlineColor);
}

void EndGameWidget::SetScoreText(int FinalScore)
{
	std::string FinalString = "Final Score: " + std::to_string(FinalScore);
	EndScore.setString(FinalString);
}

void EndGameWidget::FrameTime(float dt)
{
	Manager->Window->draw(EndScore);
	Manager->Window->draw(RestartGame.ButtonOutline);
	Manager->Window->draw(RestartGame.ButtonText);
}

void EndGameWidget::ButtonClickCheck(sf::Event EventType)
{
	//If the mouse button is left and we clicked within the bounds of the ButtonOutline
	if (EventType.mouseButton.button == sf::Mouse::Left &&
		RestartGame.ButtonOutline.getGlobalBounds().contains(EventType.mouseButton.x, EventType.mouseButton.y))
	{
		Manager->StartGame();
	}
}

