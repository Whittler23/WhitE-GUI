#include <WhitEGUI/guiManager.hpp>
#include <WhitEGUI/guiContainer.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow renderWindow(sf::VideoMode(1900.f, 1080.f), "Sandbox");
	WeGui::GuiManager guiManager(renderWindow);

	auto testWidget = guiManager.createWidget<WeGui::Widget>("testWidget");
	testWidget->setPosition(sf::Vector2f(50.f, 50.f));
	testWidget->setSize(sf::Vector2f(500.f, 500.f));

	auto testWidget2 = guiManager.createWidget<WeGui::Widget>("testWidget2");
	testWidget2->setPosition(sf::Vector2f(50.f, 50.f));
	testWidget2->setSize(sf::Vector2f(250.f, 250.f));
	testWidget->addChild(testWidget2);


	while (renderWindow.isOpen())
	{
		sf::Event event;
		while (renderWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					std::cout << event.mouseButton.x << " " << event.mouseButton.y << std::endl;
					guiManager.mGuiContainer.get("testWidget")->setPosition(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
					break;
				}
				else
				{
					auto widget = guiManager.mGuiContainer.get("testWidget");
					auto position = widget->getPosition();
					position += widget->getSize();
					auto pressPosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
					auto newSize = pressPosition - position;
					guiManager.mGuiContainer.get("testWidget")->setSize(widget->getSize()+newSize);
					break;
				}
			case sf::Event::Closed:
				renderWindow.close();
				break;
			default:
				break;
			}
		}

		renderWindow.clear();
		guiManager.draw();
		renderWindow.display();
	}


}