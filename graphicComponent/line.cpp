#include "stdafx.h"
#include "component.h"
#include "line.h"

line::line():component()
{
}

line::line(int x, int y) : component(x, y)
{
}

line::line(int x, int y, int width, int height) : component(x, y, width, height)
{
}

void line::onClick(int x, int y)
{
	component::onClick(x, y);
}


line::~line()
{
}
