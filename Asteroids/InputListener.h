#pragma once
#include "SFML/Graphics.hpp"
#include "VoidDelegate.h"
#include <memory>
#include <functional>

class InputListener
{
public:
    InputListener(const sf::Keyboard::Key& key, const std::string& name);
    InputListener() {}

protected:
    sf::Keyboard::Key listenKey;
    std::string inputName;
    bool pressed;

public:
    std::unique_ptr<Delegate<void, void>> onPressed;
    std::unique_ptr<Delegate<void, void>> onHeld;
    std::unique_ptr<Delegate<void, void>> onReleased;


public:
    std::string GetInputName() { return inputName; }

    sf::Keyboard::Key GetKeyboardInput() { return listenKey; }

    bool IsPressed() { return pressed; }

    void SetPressed(bool newState) { pressed = newState; }
};