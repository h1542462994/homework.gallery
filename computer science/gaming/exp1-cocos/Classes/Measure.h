#pragma once
#include <cocos2d.h>
#include "Locator.h"
#include <HorizontalAxis.h>


using namespace cocos2d;

// record for object's location and size
class Measure
{
private:
	Locator* locator = nullptr;
public:
	Measure(Vec2 location, Size size);
	Vec2 location;
	Size size;

	/*
	获取当前的Locator
	*/
	Locator& currentLocator();

	// return visibleSize - size
	Size diffSize();
	/*
	居中
	*/
	static Measure center(Size size);
	/*
	顶部居中
	*/
	static Measure topCenter(Size size);
	/*
	左上角
	*/
	static Measure topLeft(Size size);
	/*
	右上角
	*/
	static Measure topRight(Size size);
	/*
	左边
	*/
	static Measure centerLeft(Size size);
	/*
	右边
	*/
	static Measure centerRight(Size size);
	/*
	左下角
	*/
	static Measure bottomLeft(Size size);
	/*
	底部
	*/
	static Measure bottomCenter(Size size);
	/*
	右下角
	*/
	static Measure bottomRight(Size size);

	/*
	按照diffSize的百分比偏移
	*/
	Measure percentOffset(Vec2 offset);

	/*
	按照绝对坐标位移
	*/
	Measure absoluteOffset(Vec2 offset);

	/*
	按照size的百分比偏移
	*/
	Measure percentContentSizeOffset(Vec2 offset);

	/*
	放置在上方
	*/
	static Measure above(Measure base, Size size, HorizontalAxis axis);

	/*
	放置在下方
	*/
	static Measure down(Measure base, Size size, HorizontalAxis axis);

	/*
	重新调整大小到宽度的一定比例
	*/
	static Size fitPercentWidth(Size rawSize, float width);
};

