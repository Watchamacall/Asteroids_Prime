#include "PlayerController.h"
#include "Player.h"

PlayerController::PlayerController(Actor* actorToControl)
{
    controllingActor = actorToControl;

    bindings = GameManager::GetInstance().GetKeybindings();

    bindings->AddKeyBinding("Forward", sf::Keyboard::W);
    bindings->AddDelegateToKeyBinding("Forward", [this] { MoveCharacter(); });
}

void PlayerController::FrameCall(float dt)
{
    
}

void PlayerController::MoveCharacter()
{
    if (APlayer* castedPlayer = static_cast<APlayer*>(controllingActor))
    {
        sf::Vector2f fVec = castedPlayer->GetForwardVector();
        float movFrame = forwardSpeed * GameManager::GetInstance().GetDeltaTime(); //Move 200 per 
        sf::Vector2f movementVector = sf::Vector2f(fVec.x * movFrame, fVec.y * movFrame);

        castedPlayer->Translate(movementVector);
        std::cout << "Player moved to " << castedPlayer->GetPosition().x << " " << castedPlayer->GetPosition().y << std::endl;
    }
    else
    {
        std::cout << "castedPlayer not completed" << std::endl;
    }
}
