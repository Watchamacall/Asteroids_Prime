#include "Asteroid.h"
#include "GameManager.h"
#include "Player.h"

Asteroid::Asteroid(GameManager* Manager, const char* TextureLoc) : Actor(Manager, TextureLoc)
{
}
Asteroid::~Asteroid()
{
}

void Asteroid::FrameTime(float dt)
{
	Actor::FrameTime(dt);

	Move(MoveDirection, Velocity);
}

void Asteroid::Hit(Actor* Other)
{
	if (!dynamic_cast<Projectile*>(Other))
	{
		return;
	}

	Break();
	Manager->AddScore(DestoryScore);
	if (Sprite.getScale() == sf::Vector2f(0.33f,0.33f))
	{
		std::cout << "Deletion" << std::endl;
	}
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

		if (this->Sprite.getScale() == sf::Vector2f(1.f, 1.f))
		{
			NewAst->Sprite.setScale(MediumAstSize);
			std::cout << "Size is 1,1" << std::endl;
		}
		else
			NewAst->Sprite.setScale(SmallAstSize);
		NewAst = nullptr;
	}
}
