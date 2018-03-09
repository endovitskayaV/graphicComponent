#pragma once
#include <string>
#include "complexComponent.h"

using namespace std;
class window :public complexComponent
{
public:
	string title;
	void onClick(int x, int y);
	window();
	window(int x, int y);
	window(int x, int y, int width, int height);
	~window();

};