#pragma once
#include "component.h"
class line :
	public component
{
public:
	line();
	line(int x, int y);
	line(int x, int y, int width, int height);
	void onClick(int x, int y);
	~line();
};