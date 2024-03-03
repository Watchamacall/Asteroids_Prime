#include "Actor.h"
#include "GameManager.h"

Actor::Actor(GameManager* Manager, const char* TextureLoc)
{
	this->Manager = Manager;
	if (!Texture.loadFromFile(TextureLoc))
	{
		//Handle error with not loading Texture
	}
	TextureLocation = TextureLoc;
	Sprite = sf::Sprite(Texture);
}

Actor::~Actor()
{
	Manager = nullptr;
}
void Actor::Hit(Actor* Other)
{

}

void Actor::Move(float MoveDirection, float MoveSpeed)
{
	Sprite.move(GameManager::DegreesToVector2f(MoveDirection) * (MoveSpeed * Manager->dt.asSeconds()));
	//Play Sound

	sf::Vector2f CurPosition = Sprite.getPosition();
	if (Sprite.getPosition().x < 0)
		Sprite.setPosition(CurPosition.x += Manager->Window->getSize().x, CurPosition.y); // Wrap from left to right

	else if (Sprite.getPosition().x >= Manager->Window->getSize().x)
		Sprite.setPosition(CurPosition.x -= Manager->Window->getSize().x, CurPosition.y);

	if (Sprite.getPosition().y < 0)
		Sprite.setPosition(CurPosition.x, CurPosition.y += Manager->Window->getSize().y);
	else if (Sprite.getPosition().y >= Manager->Window->getSize().y)
		Sprite.setPosition(CurPosition.x, CurPosition.y -= Manager->Window->getSize().y);

}

void Actor::FrameTime(float dt)
{
	Manager->Window->draw(this->Sprite);
}

bool Actor::CollidedWith(Actor* Other)
{
	return Sprite.getGlobalBounds().intersects(Other->Sprite.getGlobalBounds());
}
