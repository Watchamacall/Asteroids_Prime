#include "PlayerController.h"
#include "Player.h"
#include "GameState.h"

void PlayerController::FrameCall(float dt)
{
    keyboardHandle->CheckInputs();
}

void PlayerController::RotateCharacter(float rotationDirection)
{
    if (APlayer* castedPlayer = dynamic_cast<APlayer*>(owner))
    {
        float deltaSpeed = (rotationSpeed * GameManager::GetInstance().GetDeltaTime());
        castedPlayer->Rotate(deltaSpeed * rotationDirection);
        // std::cout << "RotSpeed: " << deltaSpeed << std::endl;
    }
}

void PlayerController::WrapCheck()
{
    if (APlayer* castedPlayer = dynamic_cast<APlayer*>(owner))
    {
        sf::Vector2f PlayerPos = castedPlayer->GetPosition();
        //If the Player is over the right hand side
        if (PlayerPos.x > GameManager::GetInstance().GetWindowSize().x)
        {
            PlayerPos.x = 0;
        }
        //If Player x is less than 0
        else if (PlayerPos.x < 0)
        {
            PlayerPos.x = GameManager::GetInstance().GetWindowSize().x;
        }

        //If Player is higher than WindowSize
        if (PlayerPos.y > GameManager::GetInstance().GetWindowSize().y)
        {
            PlayerPos.y = 0;
        }
        //If Player is lower than 0
        else if (PlayerPos.y < 0)
        {
            PlayerPos.y = GameManager::GetInstance().GetWindowSize().y;
        }
        
        castedPlayer->SetPosition(PlayerPos);
    }
    
}

void PlayerController::ShootProjectile()
{
    AProjectile* NewProjectile = GameManager::GetInstance().GetCurrentGameState()->GetActorManager()->CreateNewActor<AProjectile>("ShipProjectile", "Assets/Asteroid.png", owner->GetCenter(), owner);
    NewProjectile->SendInDirection(owner->GetForwardVector());
}

void PlayerController::MoveCharacter(float movementDirection)
{
    if (APlayer* castedPlayer = dynamic_cast<APlayer*>(owner))
    {
        sf::Vector2f fVec = castedPlayer->GetForwardVector() * movementDirection; //-1 if moving backward, 1 if moving forward
        float movFrame = forwardSpeed * GameManager::GetInstance().GetDeltaTime(); //How far to move forward in a singular frame
        sf::Vector2f movementVector = sf::Vector2f(fVec.x * movFrame, fVec.y * movFrame);

        castedPlayer->Translate(movementVector);
        // std::cout << "Player moved to " << castedPlayer->GetPosition().x << " " << castedPlayer->GetPosition().y << std::endl;
        WrapCheck();
    }
    else
    {
        std::cout << "castedPlayer not completed" << std::endl;
    }
}
