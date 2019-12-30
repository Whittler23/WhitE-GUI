#include "WhitEGUI/widget.hpp"
#include "WhitEGUI/guiContainer.hpp"

namespace WeGui {

Widget::Widget()
	:mParent(nullptr)
	,mWidgetName("widget")
	,mWidgetProperties(0.f, 0.f, 0.f, 0.f, sf::Vector2f(0.f, 0.f))
{
}

Widget::Widget(const std::string& widgetName)
	:mParent(nullptr)
	,mWidgetName(widgetName)
	,mWidgetProperties(0.f, 0.f, 0.f, 0.f, sf::Vector2f(0.f, 0.f))
{
}

void Widget::draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const
{
	sf::RectangleShape border(getSize());
	border.setPosition(getPosition());
	border.setFillColor(sf::Color(0, 0, 255, 100));
	border.setOutlineColor(sf::Color(255, 0, 0, 100));
	border.setOutlineThickness(5.f);
	renderTarget.draw(border, renderStates);
}

void Widget::setParent(GuiContainer* parentContainer)
{
 	mParent = parentContainer;
}

GuiContainer* Widget::getParent() const
{
	if (!mParent)
		return nullptr;
	else
		return mParent;
}

void Widget::setTexture(sf::Texture& widgetTexture)
{
	mSprite.setTexture(widgetTexture);
}

bool Widget::hasTexture() const
{
	return mSprite.getTexture();
}

const sf::Texture* Widget::getTexture() const
{
	return mSprite.getTexture();
}

void Widget::setPercentageSize(float percentageSizeX, float percentageSizeY)
{
	setPercentageSize(sf::Vector2f(percentageSizeX, percentageSizeY));
}

void Widget::setPercentageSize(sf::Vector2f percentageSize)
{
	mWidgetProperties.setPercentageSize(percentageSize, mParent->getSize());
}

void Widget::setSize(float sizeX, float sizeY)
{
	setSize(sf::Vector2f(sizeX, sizeY));
}

void Widget::setSize(sf::Vector2f size)
{
	mWidgetProperties.setSize(size);
}

sf::Vector2f Widget::getSize() const
{
	return mWidgetProperties.getSize();
}

sf::Vector2f Widget::getPercentSize() const
{
	return mWidgetProperties.getPercentageSize(getParent()->getContainerSize());
}

void Widget::setPercentagePosition(float percentagePositionX, float percentagePositionY)
{
	setPercentagePosition(sf::Vector2f(percentagePositionX, percentagePositionY));
}

void Widget::setPercentagePosition(sf::Vector2f percentagePosition)
{
	mWidgetProperties.setPercentagePosition(percentagePosition, mParent->getSize());
}

void Widget::setPosition(float positionX, float positionY)
{
	setPosition(sf::Vector2f(positionX, positionY));
}

void Widget::setPosition(sf::Vector2f position)
{
	mWidgetProperties.setPosition(position);
}

sf::Vector2f Widget::getPosition() const
{
	return mWidgetProperties.getPosition();
}

sf::Vector2f Widget::getPercentPosition() const
{
	return mWidgetProperties.getPercentagePosition(getParent()->getContainerSize());
}

std::string Widget::getName() const
{
	return mWidgetName;
}

/////////////////////////////////////////////////////////////
						//PRIVATE
/////////////////////////////////////////////////////////////
	
void Widget::recalculateValues(const sf::Vector2f& prevViewSize)
{
	if(mParent)
		mWidgetProperties.recalculateValues(prevViewSize, mParent->getSize());
}

/////////////////////////////////////////////////////////////

}