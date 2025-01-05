#pragma once

#include "SFML/Graphics.hpp"
#include <string>
#include <map>
#include <unordered_map>
#include <functional>
#include <memory>
#include "VoidDelegate.h"
class KeyBindings
{
protected:
	/*
	* Maps a key to a string
	* char = Keyboard Key Pressed
	* std::string = Name of Binding
	*/
	std::unordered_map<sf::Keyboard::Key, std::string> keyBindings;
	/*
	* Maps a Binding to a vector of Delegates
	* std::string = Binding Name
	* std::vector<VoidDelegate> = Delegates to be called when Binding is pressed
	*/
	std::unordered_map<std::string, VoidDelegate> pressedDelegate;

public:
	void AddKeyBinding(const std::string& keyName, sf::Keyboard::Key key);

	void AddDelegateToKeyBinding(const std::string& keyName, const std::function<void()>& delegate);

	void HandleInput(sf::Keyboard::Key key);

	std::vector<sf::Keyboard::Key> GetKeys();

	void ExecuteDelegate(sf::Keyboard::Key key);
};

