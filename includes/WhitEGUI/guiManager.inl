#include <string>
#include "guiManager.hpp"

namespace WeGui {

template<typename T>
T* GuiManager::createWidget(const std::string& widgetName)
{
	std::unique_ptr<T> widget = std::make_unique<T>();
	widget->setParent(&mGuiContainer);
	T* widgetPtr = widget.get();
	mGuiContainer.addWidget(widgetName, std::move(widget));
	return widgetPtr;
}

template<typename T>
inline T* GuiManager::createWidget(const std::string& widgetName, const std::string& targetContainerName)
{
	std::unique_ptr<T> widget = std::make_unique<T>();
	widget->setParent(&mGuiContainer.get(targetContainerName));
	T* widgetPtr = widget.get();
	mGuiContainer.addWidget(widgetName, std::move(widget));
	return widgetPtr;
}

template<typename T>
inline T* GuiManager::createWidget(const std::string& widgetName, GuiContainer* targetContainer)
{
	std::unique_ptr<T> widget = std::make_unique<T>();
	widget->setParent(targetContainer);
	T* widgetPtr = widget.get();
	targetContainer->addWidget(widgetName, std::move(widget));
	return widgetPtr;
}

}