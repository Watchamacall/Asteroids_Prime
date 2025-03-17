#include "InputListener.h"
#include <iostream>

InputListener::InputListener(const sf::Keyboard::Key& key, const std::string& name)
{
    listenKey = key;
    inputName = name;
    onPressed = std::make_unique<Delegate<void,void>>();
    onHeld = std::make_unique<Delegate<void,void>>();
    onReleased = std::make_unique<Delegate<void,void>>();
    std::cout << "InputListener created" << std::endl;
}
