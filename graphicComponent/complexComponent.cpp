#include "stdafx.h"
#include "complexComponent.h"
#include <iostream>

complexComponent::complexComponent() :component()
{
	setSize();
}

complexComponent::complexComponent(int x, int y) : component(x, y)
{
	setSize();
}

complexComponent::complexComponent(int x, int y, int width, int height) : component(x, y, width, height)
{
}

complexComponent::~complexComponent()
{
}

void complexComponent::setSize()
{
	_width = 50;
	_height = 50;
}

list<component*> complexComponent::getComponents()
{
	return _components;
}


void complexComponent::addComponent(component* component)
{
	if (!_isVisible) component->_isVisible = false;
	component->_parent = this;
	_components.emplace_front(component);
}

void complexComponent::onClick(int x, int y)
{
	for (component* c : _components) {
		if (c->isClicked(x, y)) {
			c->onClick(x, y);
			return;
		}
	}

	if (isClicked(x, y)) component::onClick(x, y);
	else cout << "You clicked on blank area" << endl;
}

component * complexComponent::findChildById(int id)
{
	if (_id == id) return this;
	for each (component* c in getComponents())
	{
		if (c->getId() == id) return c;
		return ((complexComponent*)c)->findChildById(id);
	}
}
