#include "PlayerController.h"

PlayerController::PlayerController()
{
    bindings = std::make_unique<KeyBindings>();

    bindings->AddKeyBinding("Forward", 'w');
    bindings->AddDelegateToKeyBinding("Forward", [this] { PrintString(); });
}

void PlayerController::FrameCall(float dt)
{
    bindings->HandleInput('w');
}

void PlayerController::PrintString()
{
    std::cout << "Printing KEY 'W'" << std::endl;
}
