#include "Button.h"

Button::Button()
{

}

Button::Button(const sf::Vector2f ButtonOutlineSize, const sf::Vector2f ButtonOutlinePositionOffset, const sf::Vector2f ButtonTextSizeOffset, const char* ButtonTextChar, const sf::Color ButtonOutlineColor)
{
	TextFont.loadFromFile(FontLocation);
	ButtonOutline = sf::RectangleShape(ButtonOutlineSize);
	ButtonOutline.setPosition(ButtonOutlinePositionOffset);
	ButtonOutline.setFillColor(ButtonOutlineColor);

	ButtonText = sf::Text();
	ButtonText.setString(ButtonTextChar);
	//ButtonText.setFont(TextFont);
	ButtonText.setPosition(ButtonOutline.getPosition() + ButtonTextSizeOffset);
}