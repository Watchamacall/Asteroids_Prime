#pragma once

#include "SFML/Graphics.hpp"
#include <string>
#include <map>
#include <unordered_map>
#include <functional>
#include <memory>
#include "VoidDelegate.h"
#include "InputListener.h"
#include "iostream"	

/*
 * Main thing to do:
 * - Input Class which holds which button is to be listened for
 * - Have Delegate added for pressed, released
 * - Example: InputListener(sf::Keyboard::Key key, std::string name)
 * - InputListener::AddOnPressed(VoidDelegate)
 * - InputListener::ExecuteOnPressed()
 */
class KeyBindings
{
protected:
	std::vector<std::unique_ptr<InputListener>> inputs;

	std::unordered_map<sf::Keyboard::Key, bool> prevKeyState;

public:
	InputListener* CreateNewInput(const std::string& inputName, const sf::Keyboard::Key& listenKey);

	void KeyCheck();

	InputListener* GetInput(std::string name);
};
