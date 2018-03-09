#pragma once
#include <string>
#include <list>
#include "component.h"
using namespace std;
class complexComponent :public component
{
protected:
	list<component*> _components;
	void setSize();
public:
	complexComponent();
	complexComponent(int x, int y);
	complexComponent(int x, int y, int width, int height);
	~complexComponent();
	void addComponent(component* component);
	list<component*> getComponents();
	component* findChildById(int id);
	virtual void onClick(int x, int y) = 0;
};
