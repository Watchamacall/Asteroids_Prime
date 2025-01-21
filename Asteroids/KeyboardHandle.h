#pragma once
#include <functional>
#include "SFML/Graphics.hpp"
#include "KeyBindings.h"
#include "iostream"

class KeyboardHandle
{
public:
    KeyboardHandle() { bindings = std::make_unique<KeyBindings>(); };

protected:
    std::unique_ptr<KeyBindings> bindings;

public:
    void CheckInputs();

    KeyBindings* GetKeyBindings() { return bindings.get(); }
};