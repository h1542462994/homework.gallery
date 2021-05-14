#include "Measure.h"

Measure::Measure(Vec2 location, Size size) {
	this->location = location;
	this->size = size;
}

Locator& Measure::currentLocator()
{
	if (locator == nullptr)
	{
		return Locator::getInstance();
	}
	else
	{
		return *locator;
	}
}

Size Measure::diffSize()
{
	return currentLocator().getVisibleSize() - this->size;
}

Measure Measure::center(Size size)
{
	auto& locator = Locator::getInstance();
	return Measure(locator.centerLocation(), size);
}

Measure Measure::topCenter(Size size)
{
	return Measure::center(size).percentOffset(Vec2(0, 0.5));
}

Measure Measure::topLeft(Size size)
{
	return Measure::center(size).percentOffset(Vec2(-0.5, 0.5));
}

Measure Measure::topRight(Size size)
{
	return Measure::center(size).percentOffset(Vec2(0.5, 0.5));
}

Measure Measure::centerLeft(Size size)
{
	return Measure::center(size).percentOffset(Vec2(-0.5, 0));
}

Measure Measure::centerRight(Size size)
{
	return Measure::center(size).percentOffset(Vec2(0.5, 0));
}

Measure Measure::bottomLeft(Size size)
{
	return Measure::center(size).percentOffset(Vec2(-0.5, -0.5));
}

Measure Measure::bottomCenter(Size size)
{
	return Measure::center(size).percentOffset(Vec2(0, -0.5));
}



Measure Measure::bottomRight(Size size)
{
	return Measure::center(size).percentOffset(Vec2(0.5, -0.5));
}

Measure Measure::percentOffset(Vec2 offset)
{
	Size _diffSize = diffSize();
	Vec2 _diff = Vec2(_diffSize.width * offset.x, _diffSize.height * offset.y);
	return this->absoluteOffset(_diff);
}

Measure Measure::absoluteOffset(Vec2 offset)
{
	return Measure(this->location + offset, this->size);
}

Measure Measure::percentContentSizeOffset(Vec2 offset)
{
	Vec2 _diff = Vec2(size.width * offset.x, size.height * offset.y);
	return this->absoluteOffset(_diff);
}

Measure Measure::above(Measure base, Size size, HorizontalAxis axis)
{
	Vec2 _diff = Vec2(base.size.width * axis.baseOffset - size.width * axis.targetOffset, base.size.height / 2 + size.height / 2);
	return Measure(base.location + _diff, size);
}

Measure Measure::down(Measure base, Size size, HorizontalAxis axis)
{
	return Measure(base.location, size);
}

Size Measure::fitPercentWidth(Size rawSize, float width)
{
	float percent = width * Locator::getInstance().getVisibleSize().width / rawSize.width;
	rawSize = rawSize * percent;
	return rawSize;
}


