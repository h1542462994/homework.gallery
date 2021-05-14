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
	��ȡ��ǰ��Locator
	*/
	Locator& currentLocator();

	// return visibleSize - size
	Size diffSize();
	/*
	����
	*/
	static Measure center(Size size);
	/*
	��������
	*/
	static Measure topCenter(Size size);
	/*
	���Ͻ�
	*/
	static Measure topLeft(Size size);
	/*
	���Ͻ�
	*/
	static Measure topRight(Size size);
	/*
	���
	*/
	static Measure centerLeft(Size size);
	/*
	�ұ�
	*/
	static Measure centerRight(Size size);
	/*
	���½�
	*/
	static Measure bottomLeft(Size size);
	/*
	�ײ�
	*/
	static Measure bottomCenter(Size size);
	/*
	���½�
	*/
	static Measure bottomRight(Size size);

	/*
	����diffSize�İٷֱ�ƫ��
	*/
	Measure percentOffset(Vec2 offset);

	/*
	���վ�������λ��
	*/
	Measure absoluteOffset(Vec2 offset);

	/*
	����size�İٷֱ�ƫ��
	*/
	Measure percentContentSizeOffset(Vec2 offset);

	/*
	�������Ϸ�
	*/
	static Measure above(Measure base, Size size, HorizontalAxis axis);

	/*
	�������·�
	*/
	static Measure down(Measure base, Size size, HorizontalAxis axis);

	/*
	���µ�����С����ȵ�һ������
	*/
	static Size fitPercentWidth(Size rawSize, float width);
};

