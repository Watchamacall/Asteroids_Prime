#include "PlayerController.h"
#include "Player.h"

PlayerController::PlayerController(Actor* actorToControl)
{
    controllingActor = actorToControl;

    bindings = GameManager::GetInstance().GetKeybindings();

    forward = bindings->CreateNewInput("Forward", sf::Keyboard::W);
    forward->AddOnHeld([this] { MoveCharacter(1); });

    right = bindings->CreateNewInput("Right", sf::Keyboard::D);
    right->AddOnHeld([this] { RotateCharacter(1); });

    backward = bindings->CreateNewInput("Backwards", sf::Keyboard::S);
    backward->AddOnHeld([this] { MoveCharacter(-1); });

    left = bindings->CreateNewInput("Left", sf::Keyboard::A);
    left->AddOnHeld([this] { RotateCharacter(-1); });

    shoot = bindings->CreateNewInput("Shoot", sf::Keyboard::Space);
    shoot->AddOnReleased([this] { ShootProjectile(); });
}

void PlayerController::FrameCall(float dt)
{
    
}

void PlayerController::RotateCharacter(float rotationDirection)
{
    if (APlayer* castedPlayer = static_cast<APlayer*>(controllingActor))
    {
        float deltaSpeed = (rotationSpeed * GameManager::GetInstance().GetDeltaTime());
        castedPlayer->Rotate(deltaSpeed * rotationDirection);
        // std::cout << "RotSpeed: " << deltaSpeed << std::endl;
    }
}

void PlayerController::WrapCheck()
{
    if (APlayer* castedPlayer = static_cast<APlayer*>(controllingActor))
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
    AProjectile* NewProjectile = GameManager::GetInstance().GetActorManager()->CreateNewActor<AProjectile>("ShipProjectile", "Assets/Asteroid.png");
    NewProjectile->SetPosition(controllingActor->GetPosition());
    NewProjectile->SendInDirection(controllingActor->GetForwardVector());

    std::cout << "Spawned New Projectile" << std::endl;
}

void PlayerController::MoveCharacter(float movementDirection)
{
    if (APlayer* castedPlayer = static_cast<APlayer*>(controllingActor))
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
