# 游戏程序开发设计实验1报告

## 一、实验目的

本次实验主要是配置Cocos2d-x引擎的环境，并且学习Cocos2d-x的基础知识。能够了解游戏引擎的基本概念。

## 二、实验步骤

1、下载Cocos2d-x的源码。[下载地址](https://www.cocos.com/cocos2dx)，然后将其放置到合适的位置（例如我装在C:\Green\cocos2d-x-4.0\）

2、准备好基础的环境，包括cmake编译环境以及python2.7。在这里为了方便，因此使用Visual Studio提供的cmake环境。

- cmake: 打开Visual Studio Installer，选择修改->单个组件->找到适合C++的动态编译环境并安装，然后等待安装完毕。
- python 2.7: 打开[python的官网](https://www.python.org/downloads/)，找到python2.7.18版本，进行安装。

3、配置好环境变量

```
#cmake
Path:=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin
#java
JAVA_HOME=C:\Program Files\Java\jdk1.8.0_221
CLASSPATH=%JAVA_HOME%\lib;%JAVA_HOME%\lib\tools.jar
Path:=%JAVA_HOME%\bin
#python
PYTHON_HOME=C:\Program Files\Python27
Path:=%PYTHON_HOME%
```

环境变量主要是便于cocos2d-x找到依赖的位置。

4、下载依赖和安装

使用python2.7运行脚本`download-deps.py`，完成依赖的下载。然后运行脚本`setup.py`，完成安装。

到这里，cocos-2dx就算安装好了。

5、创建新的项目

首先在你需要创建项目的位置按住shift+右键，选择powershell脚本，运行下面命令创建项目

```
cocos new [Demo1] -p win32 -l cpp
```

其中-p表示指定平台，-l表示指定开发语言。

4、编译项目

使用cocos run编译项目，有时候会出现错误。

找到`proj.win32`子文件夹并打开，运行下列命令。

```
cmake … -G"Visual Studio 16 2019" -Tv142 -A win32 …
```

然后打开Demo1.sln文件，然后设置Demo1为默认项目，启动的目标平台为Win32，点击运行。

5、阅读代码

在cocos项目中，代码主要位于平台无关的代码目录`Classes`中，其中并没有main.h，main.cpp模块，这是因为不同平台的启动方式不同。在cocos中，使用了AppDelegate表示App的委托类，其中定义了应用状态切换的关键代码。

而HelloWorldScene.cpp表示主场景，一个场景就相当于电影中构图相对不变的一幕，Director表示导演，其使用单例模式，然后控制场景切换的逻辑。由于开始时只有一个HelloWorldScene，因此暂时不涉及到场景的切换

```cpp
auto visibleSize = Director::getInstance()->getVisibleSize();
Vec2 origin = Director::getInstance()->getVisibleOrigin();
```

上面的代码是进行布局和定位的关键参数，其中origin表示画布中原点的位置，visibleSize表示可使大小。

```cpp
// position the label on the center of the screen
label->setPosition(Vec2(origin.x + visibleSize.width/2 - sprite->getContentSize().width /2,
                        origin.y + visibleSize.height/2 - sprite->getContentSize().height /2));
```

上面的代码是典型的进行布局定位的代码，从代码中我们可以发现，控件的布局原点是其中心点（默认）。

当然上面的代码是不太美观的，因此我们从中抽象出定位的逻辑代码。来辅助进行布局的定位。

下面是相关的代码

### 类Location

```cpp
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
```

### 类Measure

```cpp
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
```

### 类HorizontalAxis

```cpp
#pragma once
class HorizontalAxis
{
public:
	HorizontalAxis(float baseOffset = 0, float targetOffset = 0) {
		this->baseOffset = baseOffset;
		this->targetOffset = targetOffset;
	}
	float baseOffset;
	float targetOffset;

	static HorizontalAxis CenterToCenter() {
		return HorizontalAxis(0, 0);
	}
};
```

### 使用方法：

```cpp
// add "HelloWorld" splash screen"
auto sprite = Sprite::create("HelloWorld.png");
if (sprite == nullptr)
{
    problemLoading("'HelloWorld.png'");
}
else
{
    sprite->setContentSize(Measure::fitPercentWidth(sprite->getContentSize(), 1.0 / 17.0));
    // 计算测量对象
    Measure spriteMeasure = Measure::bottomRight(sprite->getContentSize()).percentContentSizeOffset(Vec2(-0.3, 0.3));

    // position the sprite on the center of the screen
    sprite->setPosition(spriteMeasure.location);


    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
}




auto wall = Sprite::create("wall.png");

if (wall == nullptr)
{
    problemLoading("'wall.png'");
}
else
{
    // 调整大小
    wall->setContentSize(Measure::fitPercentWidth(wall->getContentSize(), 1.0 / 9.0));
    // 计算度量值
    Measure measure = Measure::bottomCenter(wall->getContentSize()).percentContentSizeOffset(Vec2(0, 1));
    wall->setPosition(measure.location);
    this->addChild(wall, 0);

    Measure spriteMeasure = Measure::above(measure, sprite->getContentSize(), HorizontalAxis::CenterToCenter());
    sprite->setPosition(spriteMeasure.location);
}
```

上边的代码表示将sprite放置在wall的上方。

其中`Measure::center(Size size)`表示布局到中心点，其范围的是一个Measure对象，其成员location表示当前的布局位置。Measure提供了三种成员函数

其中`percentOffset()`表示按照屏幕的大小-物体的大小为活动范围按照百分比进行偏移。

例如`Measure::center(wall->getContentSize()).percentOffset(Vec2(0.5, 0.5))`会将其定位右上角。

`absoluteOffset()`表示绝对偏移，`percentContentSizeOffset()`表示按照物体的大小比例进行偏移。

除了提供从九个位置进行开始布局外，还提供了4种方式来进行相对控件的布局。（暂时写了两种，分别为上和下，以后还会完善左和右）

其中`Measure::above(Measure another, Size size, HorizontalAxis axis)`表示将物体放置在另外一个物体的上方，其中axis表示对齐方式，`HorizontalAxis::centerToCenter()`表示参照物体的中心轴和被放置物体的中心轴对齐。具体的计算方式涉及到简单2维向量的计算，在代码里也说了。