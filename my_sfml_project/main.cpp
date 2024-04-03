#include <SFML/Graphics.hpp>

int main()
{
    // Create a new window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Create a circle
    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Green);

    // Main loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear();

        // Draw the circle
        window.draw(circle);

        // Display what has been drawn
        window.display();
    }

    return 0;
}