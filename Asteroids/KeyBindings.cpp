#include "KeyBindings.h"

InputListener* KeyBindings::CreateNewInput(const std::string& inputName, const sf::Keyboard::Key& listenKey)
{
	std::unique_ptr<InputListener> newInput = std::make_unique<InputListener>(listenKey, inputName);
	InputListener* returnPtr = newInput.get();
	inputs.push_back(std::move(newInput));
	return returnPtr;
}

void KeyBindings::KeyCheck()
{
	for (auto& input : inputs)
	{
		sf::Keyboard::Key key = input->GetKeyboardInput();
		bool curInput = sf::Keyboard::isKeyPressed(key);

		if (curInput && !prevKeyState[key])
			input->onPressed->Execute();
		else if (curInput && prevKeyState[key])
		{
			input->onHeld->Execute();
		}
		else if (!curInput && prevKeyState[key])
			input->onReleased->Execute();

		prevKeyState[key] = curInput;
	}

	
}

InputListener* KeyBindings::GetInput(std::string name)
{
	for (auto& input : inputs)
	{
		if (input->GetInputName() == name)
		{
			return input.get();
		}
	}
	
    return nullptr;
}
