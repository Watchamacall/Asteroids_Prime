#include "InputListener.h"

InputListener::InputListener(const sf::Keyboard::Key& key, const std::string& name)
{
    listenKey = key;
    inputName = name;
    onPressed = std::make_unique<VoidDelegate>();
    onHeld = std::make_unique<VoidDelegate>();
    onReleased = std::make_unique<VoidDelegate>();
}

void InputListener::AddOnPressed(std::function<void()> function)
{
    onPressed->AddVoidDelegate(function);
}

void InputListener::AddOnHeld(std::function<void()> function)
{
    onHeld->AddVoidDelegate(function);
}

void InputListener::AddOnReleased(std::function<void()> function)
{
    onReleased->AddVoidDelegate(function);
}
