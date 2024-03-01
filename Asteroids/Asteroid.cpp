#include "Asteroid.h"
#include "GameManager.h"
#include "Player.h"

Asteroid::Asteroid(GameManager* Manager) : Actor(Manager)
{
}

void Asteroid::FrameTime(float dt)
{
	Sprite.move(GameManager::DegreesToVector2f(MoveDirection) * (Velocity * dt));
}

void Asteroid::Hit(Actor* Other)
{
	if (!dynamic_cast<Player*>(Other))
	{
		return;
	}

	Break();
	Manager->AddScore(DestoryScore);
	Manager->Remove(this);
}

void Asteroid::Break()
{
	if (Sprite.getScale() == SmallAstSize)
	{
		return;
	}
	Asteroid* NewAst;
	for (size_t i = 0; i < BreakNum; i++)
	{
		NewAst = Manager->Spawn<Asteroid>(Sprite.getPosition());

		int AngleChange = GameManager::RandomRange(AstBreakMinAngle, AstBreakMaxAngle, true);

		//Sets the move direction
		NewAst->MoveDirection = this->MoveDirection + AngleChange;

		if (NewAst->Sprite.getScale() == sf::Vector2f(1,1))
			NewAst->Sprite.setScale(MediumAstSize);
		else
			NewAst->Sprite.setScale(SmallAstSize);
	}
}
