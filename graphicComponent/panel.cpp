#include "stdafx.h"
#include "complexComponent.h"
#include "panel.h"
#include <iostream>

panel::panel() :complexComponent()
{
}

panel::panel(int x, int y) : complexComponent(x, y)
{
}

panel::panel(int x, int y, int width, int height) : complexComponent(x, y, width, height)
{
}

panel::~panel()
{
}

void panel::onClick(int x, int y)
{
	complexComponent::onClick(x, y);
}