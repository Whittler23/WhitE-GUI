#include "WhitEGUI/guiContainer.hpp"
#include "WhitEGUI/widget.hpp"
#include "WhitEGUI/widgetProperties.hpp"
#include "WhitEGUI/guiContainer.hpp"
#include <iostream>

namespace WeGui {

/////////////////////////////////////////////////////////////
					//CONSTRUCTORS
/////////////////////////////////////////////////////////////

GuiContainer::GuiContainer()
	:Widget("GuiContainer")
{
}

/////////////////////////////////////////////////////////////
						//PUBLIC
/////////////////////////////////////////////////////////////

void GuiContainer::draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const
{
	sf::RectangleShape border(getSize());
	border.setPosition(getPosition());
	border.setFillColor(sf::Color(0, 255, 0, 100));
	renderTarget.draw(border, renderStates);

	for (const auto& widget : mWidgetsMap)
			widget.second->draw(renderTarget, renderStates);
}

void GuiContainer::addWidget(const std::string& widgetName, std::unique_ptr<Widget> newWidget)
{
	newWidget->setParent(this);
	mWidgetsMap.emplace(std::make_pair(widgetName, std::move(newWidget)));
}

void GuiContainer::remove(const std::string& widgetName)
{
	mWidgetsMap.erase(widgetName);
}

void GuiContainer::remove(const Widget& widget)
{
	for (auto it = mWidgetsMap.begin(); it != mWidgetsMap.end(); ++it)
		if (it->second.get() == &widget)
			mWidgetsMap.erase(it);
}

void GuiContainer::removeAllWidgets()
{
	mWidgetsMap.clear();
}

void GuiContainer::setSize(sf::Vector2f size)
{
	Widget::setSize(size);
	mContainerSize = size;
}

void GuiContainer::setPercentageSize(sf::Vector2f percentageSize)
{
	Widget::setPercentageSize(percentageSize);
	mContainerSize = getSize();
}

void GuiContainer::setPosition(sf::Vector2f position)
{
	auto oldPosition = getPosition();
	auto offset = position - oldPosition;
	Widget::setPosition(position);
	mContainerSize = position;
	for (const auto& widget : mWidgetsMap)
		widget.second->setPosition(widget.second->getPosition() + offset);
}

void GuiContainer::setPercentagePosition(sf::Vector2f percentagePosition)
{
	Widget::setPercentagePosition(percentagePosition);
	mContainerSize = getSize();
}

sf::Vector2f GuiContainer::getContainerSize() const
{
	return mContainerSize;
}

Widget* GuiContainer::get(const std::string& widgetName) const
{
	return mWidgetsMap.at(widgetName).get();
}

std::vector<Widget*> GuiContainer::getWidgets() const
{
	std::vector<Widget*> widgets;
	for (const auto& widget : mWidgetsMap)
		widgets.emplace_back(widget.second.get());
	return widgets;
}

}
