#pragma once
#include <functional>
#include "SFML/Graphics.hpp"
#include "KeyBindings.h"

class KeyboardHandle
{
public:
    KeyboardHandle() { bindings = std::make_unique<KeyBindings>(); };

protected:
    std::unique_ptr<KeyBindings> bindings;

public:
    void CheckInputs(sf::Event eventPoll);

    KeyBindings* GetKeyBindings() { return bindings.get(); }
};