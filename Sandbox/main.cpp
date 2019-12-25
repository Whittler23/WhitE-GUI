#include <WhitEGUI/guiManager.hpp>
#include <WhitEGUI/Widgets/button.hpp>
#include <WhitEGUI/guiContainer.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow renderWindow(sf::VideoMode(1900.f, 1080.f), "Sandbox");
	WeGui::GuiManager guiManager(renderWindow);
	auto button = guiManager.createWidget<WeGui::Button>("MainButton");
	button->setPosition(sf::Vector2f(500.f, 250.f));
	button->setSize(sf::Vector2f(500.f, 250.f));
	sf::Texture texture;

	while (renderWindow.isOpen())
	{
		sf::Event event;
		while(renderWindow.pollEvent(event))
			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
				std::cout << event.mouseButton.x << " " << event.mouseButton.y << std::endl;
				break;
			case sf::Event::Closed:
				renderWindow.close();
				break;
			default:
				break;
			}

		renderWindow.clear();
		guiManager.draw();
		renderWindow.display();
	}
}