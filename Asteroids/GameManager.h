#pragma once
#include "SFML/Graphics.hpp"

enum GameState : int8_t
{
	STATE_PAUSED = 0,
	STATE_PLAYING = 1
};

class GameManager
{
protected:
	sf::Clock gameClock;
	sf::Window gameWindow;
	GameState gameState;
};

