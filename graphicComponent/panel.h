#pragma once
#include "complexComponent.h"
class panel :public complexComponent
{
public:
	void onClick(int x, int y);
	panel();
	panel(int x, int y);
	panel(int x, int y, int width, int height);
	~panel();
};