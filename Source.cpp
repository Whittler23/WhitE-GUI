#include <SFML/Graphics.hpp>

#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "WhitEGUI");
	sf::RectangleShape shape;
	shape.setFillColor(sf::Color::Red);
	shape.setSize(sf::Vector2f(400.f, 300.f));
	shape.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
				std::cout << "Pressed!" << std::endl;
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
}