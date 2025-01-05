#include "KeyBindings.h"

void KeyBindings::AddKeyBinding(const std::string& keyName, char key)
{
	//Adds the char as the key to the Binding Name
	keyBindings[key] = keyName;
}

void KeyBindings::AddDelegateToKeyBinding(const std::string& keyName, const VoidDelegate& delegate)
{
	//pushes back the delegate ready for calling
	actionToDelegate[keyName].push_back(delegate);
}

void KeyBindings::HandleInput(char key)
{
	if (keyBindings.find(key) != keyBindings.end())
	{
		if (actionToDelegate.find(keyBindings[key]) != actionToDelegate.end())
		{
			for (VoidDelegate& aDelegate : actionToDelegate[keyBindings[key]])
			{
				aDelegate();
			}
		}
	}
}
