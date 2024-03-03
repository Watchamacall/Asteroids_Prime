#include "StartGameWidget.h"

#include "GameManager.h"
#include "Button.h"

StartGameWidget::StartGameWidget(GameManager* Manager, const sf::Vector2f ButtonPosition, const sf::Vector2f GameNamePosition, const char* GameNameText)
{
	this->Manager = Manager;

	Font.loadFromFile(FontLocation);
	GameName = sf::Text();
	GameName.setFont(Font);
	GameName.setPosition(GameNamePosition);
	GameName.setString(GameNameText);

	StartGameButton = Button(ButtonSize, ButtonPosition, ButtonTextSize, ButtonText, ButtonOutlineColor);
}

StartGameWidget::~StartGameWidget()
{
	Manager = nullptr;
}

void StartGameWidget::FrameTime(float dt)
{
	Manager->Window->draw(GameName);
	Manager->Window->draw(StartGameButton.ButtonOutline);
	Manager->Window->draw(StartGameButton.ButtonText);
}

void StartGameWidget::ButtonClickCheck(sf::Event EventType)
{
	//If the mouse button is left and we clicked within the bounds of the ButtonOutline
	if (EventType.mouseButton.button == sf::Mouse::Left &&
		StartGameButton.ButtonOutline.getGlobalBounds().contains(EventType.mouseButton.x, EventType.mouseButton.y))
	{
		Manager->StartGame();
	}
}
