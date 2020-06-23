#pragma once

#include<Windows.h>
#include<iostream>
#define setConsoleColor(color) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color)

using namespace std;

enum class consoleforecolor
{
	//黑色
	black,
	//亮白色
	highwhite,
	//蓝色
	blue,
	//红色
	red,
	//绿色
	green,
	//紫罗兰色
	violet,
	//黄色
	yellow,
	//蓝绿色
	cyan,
	//白色
	white,
	//普通色(白色)
	normal,
	//灰色
	gray,
	//靛蓝色
	indigo,
	//深红色
	darkred,
	//深绿色
	darkgreen,
	//紫色
	purple,
	//赭色
	ochre,
	//海蓝色
	seablue
};

enum class consolebackcolor
{
	//黑色
	black,
	//亮白色
	highwhite,
	//蓝色
	blue,
	//红色
	red,
	//绿色
	green,
	//紫罗兰色
	violet,
	//黄色
	yellow,
	//蓝绿色
	cyan,
	//白色
	white,
	//普通色(白色)
	normal,
	//灰色
	gray,
	//靛蓝色
	indigo,
	//深红色
	darkred,
	//深绿色
	darkgreen,
	//紫色
	purple,
	//赭色
	ochre,
	//海蓝色
	seablue
};

class consolecolorhelper {
public:
	static int getColorId(consoleforecolor color)
	{
		if (color == consoleforecolor::highwhite)
		{
			return (FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else if (color == consoleforecolor::red)
		{
			return (FOREGROUND_INTENSITY | FOREGROUND_RED);
		}
		else if (color == consoleforecolor::blue)
		{
			return (FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		}
		else if (color == consoleforecolor::green)
		{
			return (FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		}
		else if (color == consoleforecolor::violet)
		{
			return (FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
		}
		else if (color == consoleforecolor::yellow)
		{
			return (FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		}
		else if (color == consoleforecolor::cyan)
		{
			return (FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
		}
		else if (color == consoleforecolor::white)
		{
			return (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else if (color == consoleforecolor::normal)
		{
			return (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else if (color == consoleforecolor::gray)
		{
			return (FOREGROUND_INTENSITY);
		}
		else if (color == consoleforecolor::darkred)
		{
			return (FOREGROUND_RED);
		}
		else if (color == consoleforecolor::indigo)
		{
			return (FOREGROUND_BLUE);
		}
		else if (color == consoleforecolor::darkgreen)
		{
			return (FOREGROUND_GREEN);
		}
		else if (color == consoleforecolor::ochre)
		{
			return (FOREGROUND_RED | FOREGROUND_GREEN);
		}
		else if (color == consoleforecolor::purple)
		{
			return (FOREGROUND_RED | FOREGROUND_BLUE);
		}
		else if (color == consoleforecolor::seablue)
		{
			return (FOREGROUND_BLUE | FOREGROUND_GREEN);
		}
		else if (color == consoleforecolor::black)
		{
			return (0);
		}
		else
		{
			return (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
	}
	static int getColorId(consolebackcolor color)
	{
		if (color == consolebackcolor::highwhite)
		{
			return (BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
		}
		else if (color == consolebackcolor::red)
		{
			return (BACKGROUND_INTENSITY | BACKGROUND_RED);
		}
		else if (color == consolebackcolor::blue)
		{
			return (BACKGROUND_INTENSITY | BACKGROUND_BLUE);
		}
		else if (color == consolebackcolor::green)
		{
			return (BACKGROUND_INTENSITY | BACKGROUND_GREEN);
		}
		else if (color == consolebackcolor::violet)
		{
			return (BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE);
		}
		else if (color == consolebackcolor::yellow)
		{
			return (BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN);
		}
		else if (color == consolebackcolor::cyan)
		{
			return (BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN);
		}
		else if (color == consolebackcolor::white)
		{
			return (BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
		}
		else if (color == consolebackcolor::normal)
		{
			return (0);
		}
		else if (color == consolebackcolor::gray)
		{
			return (BACKGROUND_INTENSITY);
		}
		else if (color == consolebackcolor::darkred)
		{
			return (BACKGROUND_RED);
		}
		else if (color == consolebackcolor::indigo)
		{
			return (BACKGROUND_BLUE);
		}
		else if (color == consolebackcolor::darkgreen)
		{
			return (BACKGROUND_GREEN);
		}
		else if (color == consolebackcolor::ochre)
		{
			return (BACKGROUND_RED | BACKGROUND_GREEN);
		}
		else if (color == consolebackcolor::purple)
		{
			return (BACKGROUND_RED | BACKGROUND_BLUE);
		}
		else if (color == consolebackcolor::seablue)
		{
			return (BACKGROUND_BLUE | BACKGROUND_GREEN);
		}
		else if (color == consolebackcolor::black)
		{
			return (0);
		}
		else
		{
			return (0);
		}
	}
};

ostream& operator<< (ostream & out, consoleforecolor color)
{
	setConsoleColor(consolecolorhelper::getColorId(color));

	return out;
}


ostream& operator<< (ostream & out, consolebackcolor color)
{
	setConsoleColor(consolecolorhelper::getColorId(color));

	return out;
}

//组合色
class consolecolorjoin
{
public:
	explicit consolecolorjoin(consoleforecolor fore = consoleforecolor::normal, consolebackcolor back = consolebackcolor::normal) :_fore(fore), _back(back) {}

	friend ostream& operator << (ostream& out, consolecolorjoin color)
	{
		setConsoleColor(consolecolorhelper::getColorId(color._fore) | consolecolorhelper::getColorId(color._back));

		return out;
	}

	consoleforecolor fore() { return _fore; }
	consolebackcolor back() { return _back; }
private:
	consoleforecolor _fore;
	consolebackcolor _back;
};

consolecolorjoin operator + (consoleforecolor fore, consolebackcolor back)
{
	return consolecolorjoin(fore, back);
}