#include <SFML/Graphics.hpp>
#include "Actor.h"
#include "Player.h"
#include "GameManager.h"
int main()
{
    /*
        * Requirements: 
        * -	The game starts with the player ship in the center of the screen (DONE)
        * -	Their score and number of remaining lives are always visible. They start with 0 score and 3 lives (DONE)
        * -	The player can move the ship forwards, and turn left and right (DONE)
        * -	The player can shoot bullets, that fire forward in the direction the ship is facing (DONE)
        * -	Asteroids spawn from outside of the screen. They move with a constant velocity (DONE)
        * -	The screen is static, but it �wraps� for the player and asteroids. When they exit the screen on one side they reappear on the other. Bullets do not wrap (DONE)
        * -	If the player collides with an asteroid they lose a life and respawn in the center of the screen. They start with a �grace period� when they cannot collide with another asteroid
        * -	Once a player loses all their lives the game ends
        * -	When a bullet collides with an asteroid, both are destroyed and the player earns some score
        * -	When an asteroid is destroyed it splits into two smaller ones. This split happens twice (large->medium->small). The smallest asteroids do not split when destroyed (ODNE)
        * - Add One or Two new Features
        *   - The window is your ship's POV, the window itself moves alongside your ship, allowing for you to travel across your screen and shoot the asteroids
        *   - Upgrades of sorts you can get by spending your points
        */


    //Initalise GameManager
    //TODO: Turn into SharedPtr which hooks into Actors, allows for GameManager to be accessed no matter where and not locked into one place like this currently is.
    GameManager::GetInstance().InitialiseGame();

    return 0;
}