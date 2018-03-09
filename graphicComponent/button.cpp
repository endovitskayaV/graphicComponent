#include "stdafx.h"
#include "component.h"
#include "button.h"
button::button() :component()
{
}

button::button(int x, int y):component(x,y)
{
}

button::button(int x, int y, int width, int height):component(x,y,width, height)
{
}

void button::onClick(int x, int y)
{
	component::onClick(x, y);
}




button::~button()
{
}
