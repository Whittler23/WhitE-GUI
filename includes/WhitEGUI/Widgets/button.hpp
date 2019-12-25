#pragma once

#include "Widgets/clickableWidget.hpp"

namespace WeGui {

class Button : public ClickableWidget
{
public:
	Button();

	void draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const;

private:
	sf::Text mButtonText;


};

}

