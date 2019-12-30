#pragma once

#include "WhitEGUI/widget.hpp"

#include <SFML/Graphics.hpp>

#include <unordered_map>
#include <memory>

namespace WeGui {

class GuiContainer : public Widget
{
public:
	GuiContainer();

	void draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates = sf::RenderStates::Default) const override;

	void addWidget(const std::string& widgetName, std::unique_ptr<Widget> newWidget);

	void remove(const std::string& widgetName);
	void remove(const Widget& widget);
	void removeAllWidgets();

	void setSize(sf::Vector2f size) override;
	void setPercentageSize(sf::Vector2f percentageSize) override;
	void setPosition(sf::Vector2f size) override;
	void setPercentagePosition(sf::Vector2f percentageSize) override;
	sf::Vector2f getContainerSize() const;

	Widget* get(const std::string& widgetName) const;
	std::vector<Widget*> getWidgets() const;

private:
	std::unordered_map<std::string, std::unique_ptr<Widget>> mWidgetsMap;

	sf::Vector2f mContainerSize;
	sf::Vector2f mContainerPosition;
};

}