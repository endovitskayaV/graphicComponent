#include "stdafx.h"
#include "complexComponent.h"
#include "window.h"
#include <iostream>
window::window() :complexComponent()
{
}

window::window(int x, int y) : complexComponent(x,y)
{
}

window::window(int x, int y, int width, int height): complexComponent(x,y,width, height)
{
}

window::~window()
{
}

void window::onClick(int x, int y)
{	
	complexComponent::onClick(x, y);
}