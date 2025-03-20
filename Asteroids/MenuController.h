#pragma once
#include <functional>
#include <iostream>
#include "KeyBindings.h"
#include "InputListener.h"
#include "Projectile.h"
#include "GameManager.h"
#include "Component.h"

/*
* Handles all inputs for the Player and moves accordingly
*/
class MenuController : public Component
{
public:
    MenuController(Actor* owner) : Component(owner)
	{
		keyboardHandle = std::make_unique<KeyboardHandle>();

        restart = keyboardHandle->GetKeyBindings()->CreateNewInput("Restart", sf::Keyboard::Space);
        restart->onPressed->AddDelegate([this] { GoToPlay(); });

        quit = keyboardHandle->GetKeyBindings()->CreateNewInput("Quit", sf::Keyboard::Q);
        quit->onPressed->AddDelegate([this] { ExitGame(); });
	}

	virtual void FrameCall(float dt) override;

protected:
	std::unique_ptr<KeyboardHandle> keyboardHandle;
	InputListener* restart = nullptr;
    InputListener* quit = nullptr;

    void GoToPlay() { GameManager::GetInstance().ChangeToPlayState(); }
    void ExitGame() { GameManager::GetInstance().GetWindow()->close(); }
	
};

