#pragma once
#define VoidDelegate std::function<void()>

#include <string>
#include <map>
#include <unordered_map>
#include <functional>
#include <memory>

class KeyBindings
{
private:
	/*
	* Maps a key to a string
	* char = Keyboard Key Pressed
	* std::string = Name of Binding
	*/
	std::unordered_map<char, std::string> keyBindings;
	/*
	* Maps a Binding to a vector of Delegates
	* std::string = Binding Name
	* std::vector<VoidDelegate> = Delegates to be called when Binding is pressed
	*/
	std::unordered_map<std::string, std::vector<VoidDelegate>> actionToDelegate; //vector is of unfixed size, unlike []

public:
	void AddKeyBinding(const std::string& keyName, char key);

	void AddDelegateToKeyBinding(const std::string& keyName, const VoidDelegate& delegate);

	void HandleInput(char key);
};

