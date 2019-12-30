#include <WhitEGUI/guiManager.hpp>
#include <WhitEGUI/guiContainer.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow renderWindow(sf::VideoMode(1900.f, 1080.f), "Sandbox");
	WeGui::GuiManager guiManager(renderWindow);


	auto testContainer = guiManager.createWidget <WeGui::GuiContainer>("testContainer");
	testContainer->setPosition(sf::Vector2f(200.f, 25.f));
	testContainer->setSize(sf::Vector2f(200.f, 600.f));

	auto testWidget = guiManager.createWidget<WeGui::Widget>("testWidget", dynamic_cast<WeGui::GuiContainer*>(guiManager.get("testContainer")));
	testWidget->setPosition(sf::Vector2f(500.f, 50.f));
	testWidget->setSize(sf::Vector2f(500.f, 500.f));


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
					guiManager.mGuiContainer.get("testContainer")->setPosition(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
					break;
				}
				else
				{
					guiManager.mGuiContainer.setPosition(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
					break;
				}
			case sf::Event::Closed:
				renderWindow.close();
				break;
			default:
				break;
			}
		}
		////std::cout << guiManager.mGuiContainer.getSize().x << std::endl;
		//std::cout << guiManager.mGuiContainer.get("testWidget")->getSize().x << std::endl;
		renderWindow.clear();
		guiManager.draw();
		renderWindow.display();
	}


}