#include "Widget.h"
#include "GameManager.h"

Widget::Widget(GameManager* Manager)
{
	this->Manager = Manager;

	Score.setPosition(ScoreTextOffset);
	Lives.setPosition(sf::Vector2f(Manager->Window->getSize().x + LivesTextOffset.x, Manager->Window->getSize().y + LivesTextOffset.y));

}

Widget::Widget(GameManager* Manager, const std::string ScoreInitialText, const std::string LivesInitialText, const char* FontLocation)
{
	this->Manager = Manager;

	if (!font.loadFromFile(FontLocation))
	{
		return;
	}
	Score.setFont(font);
	Lives.setFont(font);

	Score.setPosition(ScoreTextOffset);
	Lives.setPosition(sf::Vector2f(Manager->Window->getSize().x + LivesTextOffset.x, LivesTextOffset.y));

	Score.setString(ScoreInitialText);
	Lives.setString(LivesInitialText);
}

Widget::~Widget()
{
}

void Widget::ChangeScore(float NewScore)
{
	Score.setString("Score: " + std::to_string(static_cast<int>(NewScore)));
}

void Widget::ChangeLives(float NewLives)
{
	Lives.setString("Lives " + std::to_string(static_cast<int>(NewLives)));
}

void Widget::FrameTime(float dt)
{
	Manager->Window->draw(Score);
	Manager->Window->draw(Lives);
}
