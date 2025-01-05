#include "PlayerController.h"

PlayerController::PlayerController()
{
    bindings = GameManager::GetInstance().GetKeybindings();

    bindings->AddKeyBinding("Forward", sf::Keyboard::W);
    bindings->AddDelegateToKeyBinding("Forward", [this] { PrintString(); });
}

void PlayerController::FrameCall(float dt)
{
    
}

void PlayerController::PrintString()
{
    std::cout << "Printing KEY 'W'" << std::endl;
}
