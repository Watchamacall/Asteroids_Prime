#pragma once
#include <SFML/Graphics.hpp>

class Button
{
public:
	/// <summary>
	/// The Outline for the Button
	/// </summary>
	sf::RectangleShape ButtonOutline;
	/// <summary>
	/// The Text for the Button
	/// </summary>
	sf::Text ButtonText;
	/// <summary>
	/// The Font of the Text
	/// </summary>
	sf::Font TextFont;
private:
	const char* FontLocation = "Assets/Font/Arial.ttf";
public:
	/// <summary>
	/// Default Constructor
	/// </summary>
	Button();
	/// <summary>
	/// Constructor with elements for the Button
	/// </summary>
	/// <param name="ButtonOutlineSize">The Size of the Outline(not the position)</param>
	/// <param name="ButtonOutlinePositionOffset">The Position for the Outline</param>
	/// <param name="ButtonTextSizeOffset">The Position for the Button Text</param>
	/// <param name="ButtonTextChar">What the Button Text says</param>
	/// <param name="ButtonOutlineColor">The Color of the Button Outine</param>
	Button(const sf::Vector2f ButtonOutlineSize, const sf::Vector2f ButtonOutlinePositionOffset, const sf::Vector2f ButtonTextSizeOffset, const char* ButtonTextChar, const sf::Color ButtonOutlineColor);
};