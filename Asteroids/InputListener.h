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
    std::unique_ptr<VoidDelegate> onPressed;
    std::unique_ptr<VoidDelegate> onHeld;
    std::unique_ptr<VoidDelegate> onReleased;
    bool pressed;

public:
    void AddOnPressed(std::function<void()> function);

    void AddOnHeld(std::function<void()> function);

    void AddOnReleased(std::function<void()> function);

    void ExecuteOnPressed() { onPressed->Execute(); }

    void ExecuteOnHeld() { onHeld->Execute(); }

    void ExecuteOnReleased() { onReleased->Execute(); }

    std::string GetInputName() { return inputName; }

    sf::Keyboard::Key GetKeyboardInput() { return listenKey; }

    bool IsPressed() { return pressed; }

    void SetPressed(bool newState) { pressed = newState; }
};