#pragma once

#include "widgetProperties.hpp"

#include <SFML/Graphics.hpp>

#include <string>

namespace WeGui {

class GuiContainer;

class Widget
{
public:
	Widget();
	Widget(const std::string& widgetName);

	virtual void draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const;

	void setParent(GuiContainer* parentContainer);
	void removeParent();
	GuiContainer* getParent() const;

	void setTexture(sf::Texture& widgetTexture);
	bool hasTexture() const;
	const sf::Texture* getTexture() const;

	void setPercentageSize(float percentageSizeX, float percentageSizeY);
	virtual void setPercentageSize(sf::Vector2f percentageSize);
	void setSize(float sizeX, float sizeY);
	virtual void setSize(sf::Vector2f size);
	sf::Vector2f getPercentSize() const;
	sf::Vector2f getSize() const;

	void setPercentagePosition(float percentagePositionX, float percentagePositionY);
	virtual void setPercentagePosition(sf::Vector2f percentagePosition);
	void setPosition(float positionX, float positionY);
	virtual void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition() const;
	sf::Vector2f getPercentPosition() const;

	std::string getName() const;

	void recalculateValues(const sf::Vector2f& prevViewSize);

protected:
	WidgetProperties mWidgetProperties;
	sf::Sprite mSprite;

private:
	GuiContainer* mParent;

	std::string mWidgetName;
};

}