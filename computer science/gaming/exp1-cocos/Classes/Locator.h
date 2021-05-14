#pragma once
#include <cocos2d.h>

using namespace cocos2d;
// the locator helper for sprite,label ...
class Locator
{
	
private:
	// the global instance for AutoLocator


	static Locator *gInstance;

	//fields
	Vec2 _origin;
	Size _visibleSize;
	

public:
	Vec2 centerLocation();

	static void ensureCreated();

	static Locator& getInstance();

	static Locator* getInstancePtr();

	static void bindingDirector(Director* director);

	void setOrigin(Vec2 origin);

	void setVisibleSize(Size visibleSize);

	Vec2 getOrigin();

	Size getVisibleSize();
};





