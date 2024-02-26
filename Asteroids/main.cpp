#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "LHG Code Exercise");
    sf::Clock GameClock;

    // Grab textures and set up sprites
    sf::Texture PlayerTexture;
    sf::Texture AsteroidTexture;

    PlayerTexture.loadFromFile("Assets/Ship.png");
    AsteroidTexture.loadFromFile("Assets/Asteroid.png");

    sf::Sprite Player;
    Player.setTexture(PlayerTexture);
    sf::Sprite Asteroid;
    Asteroid.setTexture(AsteroidTexture);

    while (window.isOpen())
    {
        // Get the delta time for the game update
        sf::Time dt = GameClock.restart();

        // Poll for window being closed
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Reset the window
        window.clear();

        /*
        * Requirements: 
        * -	The game starts with the player ship in the center of the screen
        * -	Their score and number of remaining lives are always visible. They start with 0 score and 3 lives
        * -	The player can move the ship forwards, and turn left and right
        * -	The player can shoot bullets, that fire forward in the direction the ship is facing
        * -	Asteroids spawn from outside of the screen. They move with a constant velocity
        * -	The screen is static, but it “wraps” for the player and asteroids. When they exit the screen on one side they reappear on the other. Bullets do not wrap
        * -	If the player collides with an asteroid they lose a life and respawn in the center of the screen. They start with a “grace period” when they cannot collide with another asteroid
        * -	Once a player loses all their lives the game ends
        * -	When a bullet collides with an asteroid, both are destroyed and the player earns some score
        * -	When an asteroid is destroyed it splits into two smaller ones. This split happens twice (large->medium->small). The smallest asteroids do not split when destroyed
        * - Add One or Two new Features
        */
        //-----------------------------------------------------------------------------------
        // Game logic can go here

        // Player ship follows the mouse
        sf::Vector2f MousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
        Player.setPosition(MousePosition.x, MousePosition.y);
        window.draw(Player);

        // Asteroid spins in the center of the screen
        Asteroid.setPosition(400, 400);
        float Rotation = 90.0f;
        Asteroid.rotate(Rotation * dt.asSeconds());
        window.draw(Asteroid);

        //-----------------------------------------------------------------------------------
        // Display the updated game state
        window.display();
    }

    return 0;
}