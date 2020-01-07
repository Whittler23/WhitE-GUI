#include "WhitEGUI/widget.hpp"
#include "WhitEGUI/guiContainer.hpp"

namespace WeGui {

Widget::Widget()
	:mParent(nullptr)
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

void Widget::setParent(Widget* parentContainer)
{
	if(mParent != nullptr)
		mParent->removeChild(this);
	mParent = parentContainer;
}

void Widget::removeParent()
{
	mParent = nullptr;
}

Widget* Widget::getParent() const
{
	return mParent;
}

void Widget::addChild(Widget* widget)
{
	widget->setParent(this);
	mChildren.emplace_back(widget);
}

void Widget::removeChild(Widget* widget)
{
	for (auto it = mChildren.begin(); it != mChildren.end(); ++it)
		if (*it == widget)
		{
			mChildren.erase(it);
			return;
		}

}void Widget::setTexture(sf::Texture& widgetTexture)
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

void Widget::setPercentageSize(sf::Vector2f percentageSize, bool isGlobal)
{
	if (mParent && !isGlobal)
	{
		sf::Vector2f parentSize = mParent->getSize();
		setSize(sf::Vector2f(parentSize.x * percentageSize.x / 100, parentSize.y * percentageSize.y / 100));
	}
	else if (isGlobal)
	{
		//TODO
	}
}

void Widget::setSize(sf::Vector2f size)
{
	sf::IntRect oldTextureRect = mSprite.getTextureRect();
	sf::IntRect newTextureRect = mSprite.getTextureRect();
	newTextureRect.width = size.x;
	newTextureRect.height = size.y;
	mSprite.setTextureRect(newTextureRect);

	for (auto& child : mChildren)
		child->resize(sf::Vector2i(oldTextureRect.width, oldTextureRect.height), sf::Vector2i(newTextureRect.width, newTextureRect.height));
}

sf::Vector2f Widget::getSize() const
{
	auto textureRect = mSprite.getTextureRect();
	return sf::Vector2f(textureRect.width, textureRect.height);
}

sf::Vector2f Widget::getPercentSize(bool isGlobal) const
{
	//TODO
	return sf::Vector2f();
}

void Widget::setPercentagePosition(sf::Vector2f percentagePosition)
{
	//TODO
}

void Widget::setPosition(sf::Vector2f position)
{
	auto oldPosition = getPosition();
	mSprite.setPosition(position);
	for (const auto child : mChildren)
	{
		auto offset = child->getPosition() - oldPosition;
		child->setPosition(getPosition() + offset);
	}
	//TODO
}

sf::Vector2f Widget::getPosition() const
{
	//TODO
	return mSprite.getPosition();
}

sf::Vector2f Widget::getPercentPosition() const
{
	//TODO
	return sf::Vector2f(0.f, 0.f);
}

void Widget::resize(const sf::Vector2i& previousParentSize, const sf::Vector2i& currentParentSize)
{
	sf::Vector2f newSize;
	newSize.x = getSize().x / previousParentSize.x * currentParentSize.x;
	newSize.y = getSize().y / previousParentSize.y * currentParentSize.y;
	setSize(newSize);
}

}