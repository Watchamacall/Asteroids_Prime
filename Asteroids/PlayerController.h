#pragma once
#include <functional>
#include <iostream>
#include "KeyBindings.h"
#include "GameManager.h"

/*
* Handles all inputs for the Player and moves accordingly
*/
class PlayerController
{
public:
	PlayerController();

	virtual void FrameCall(float dt);
protected:
	KeyBindings* bindings;

public:
	void PrintString();
};

