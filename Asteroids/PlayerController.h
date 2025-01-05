#pragma once
#include <functional>
#include <iostream>
#include "KeyBindings.h"

/*
* Handles all inputs for the Player and moves accordingly
*/
class PlayerController
{
public:
	PlayerController();

	virtual void FrameCall(float dt);
protected:
	std::unique_ptr<KeyBindings> bindings;

public:
	void PrintString();
};

