#pragma once

#include <SFML/Graphics.hpp>

namespace WeGui {

class GuiContainer;

class Widget
{
public:
	Widget();

	virtual void draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const;

	void setParent(Widget* parentContainer);
	void removeParent();
	Widget* getParent() const;

	void addChild(Widget* widget);
	void removeChild(Widget* widget);

	void setTexture(sf::Texture& widgetTexture);
	bool hasTexture() const;
	const sf::Texture* getTexture() const;

	virtual void setPercentageSize(sf::Vector2f percentageSize, bool isGlobal = false);
	virtual void setSize(sf::Vector2f size);
	sf::Vector2f getPercentSize(bool global = false) const;
	sf::Vector2f getSize() const;

	virtual void setPercentagePosition(sf::Vector2f percentagePosition);
	virtual void setPosition(sf::Vector2f position);
	sf::Vector2f getPercentPosition() const;
	sf::Vector2f getPosition() const;

	void resize(const sf::Vector2i& previousParentSize, const sf::Vector2i& currentParentSize);

private:
	Widget* mParent;
	sf::Sprite mSprite;
	std::vector<Widget*> mChildren;
};

}