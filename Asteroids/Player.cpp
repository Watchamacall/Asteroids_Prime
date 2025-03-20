#include "Player.h"
#include "Asteroid.h"
#include "UIManager.h"
#include "PlayerLives.h"
#include "PlayerScore.h"

APlayer::APlayer(const std::string& textureLocation, const std::string& actorName) : Actor(textureLocation, actorName)
{
	controller = AddComponent<PlayerController>();

	playerLives = AddComponent<PlayerLives>();
	playerScore = AddComponent<PlayerScore>();
	uiManager = AddComponent<UIManager>();

	playerLives->damageTaken->AddDelegate([this](int damage) { uiManager->LivesChanged(damage); });
	playerLives->noLivesLeft->AddDelegate([this] { GameManager::GetInstance().ChangeToGameOverState(); });

	collisionMultiplication = 0.5f;
}

void APlayer::FrameCall(float dt)
{
	Actor::FrameCall(dt);
}

void APlayer::OnCollisionStarted(Actor* other)
{
	if (!other)
	{
		return;
	}
	
	if (dynamic_cast<AAsteroid*>(other))
	{
		std::cout << "Asteroid has hit player" << std::endl;
		playerLives->TakeDamage();
	}
}
