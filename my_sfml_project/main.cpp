#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Student Management System");

    // Font for text
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font file" << std::endl;
        return 1;
    }

    // Text for the menu options
    sf::Text menuText;
    menuText.setFont(font);
    menuText.setCharacterSize(24);
    menuText.setFillColor(sf::Color::White);
    menuText.setString("What would you like to do?\n1. Login\n0. Stop program\n\nYour choice: ");

    // Main loop
    while (window.isOpen())
    {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear();

        // Draw the text
        window.draw(menuText);

        // Display the content of the window
        window.display();
    }

    return 0;
}
