#include "Locator.h"

Locator* Locator::gInstance = nullptr;

Vec2 Locator::centerLocation() {
	return Size(_origin.x + _visibleSize.width / 2, _origin.y + _visibleSize.height / 2);
}

void Locator::ensureCreated() {
	if (Locator::gInstance == nullptr)
	{
		Locator::gInstance = new Locator();
	}
}

Locator& Locator::getInstance() {
	ensureCreated();
	return *Locator::gInstance;
}

Locator* Locator::getInstancePtr() {
	ensureCreated();
	return Locator::gInstance;
}

void Locator::bindingDirector(Director* director)
{
	Locator& autoLocator = Locator::getInstance();
	autoLocator.setOrigin(director->getVisibleOrigin());
	autoLocator.setVisibleSize(director->getVisibleSize());
}

void Locator::setOrigin(Vec2 origin) {
	this->_origin = origin;
}

void Locator::setVisibleSize(Size visibleSize) {
	this->_visibleSize = visibleSize;
}

Vec2 Locator::getOrigin()
{
	return this->_origin;
}

Size Locator::getVisibleSize()
{
	return this->_visibleSize;
}





