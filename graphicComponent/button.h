#pragma once
#include <string>
#include "component.h"
class button :public component
{
public:
	string title;
	button(int x, int y);
	button(int x, int y, int width, int height);
	void onClick(int x, int y);
	button();
	~button();
};
