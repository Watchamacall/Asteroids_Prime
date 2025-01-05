#include "KeyBindings.h"

void KeyBindings::AddKeyBinding(const std::string& keyName, sf::Keyboard::Key key)
{
	//Adds the char as the key to the Binding Name
	keyBindings[key] = keyName;
	
}

void KeyBindings::AddDelegateToKeyBinding(const std::string& keyName, const std::function<void()>& delegate)
{
	//pushes back the delegate ready for calling
	pressedDelegate[keyName].AddVoidDelegate(delegate);
}

void KeyBindings::HandleInput(sf::Keyboard::Key key)
{
	if (keyBindings.find(key) != keyBindings.end())
	{
		if (pressedDelegate.find(keyBindings[key]) != pressedDelegate.end())
		{
			pressedDelegate[keyBindings[key]].Execute();
		}
	}
}

std::vector<sf::Keyboard::Key> KeyBindings::GetKeys()
{
	std::vector<sf::Keyboard::Key> returnArray;

	for (auto& s : keyBindings)
	{
		returnArray.push_back(s.first);
	}
	
    return returnArray;
}
