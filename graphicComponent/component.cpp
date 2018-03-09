#include "stdafx.h"
#include "component.h"
#include <iostream>
#include <typeinfo>
#include <exception>
int component::_idCounter = 0;

component::component()
{
	_x = 0;
	_y = 0;
	_width =1;
	_height = 1;
	_id = _idCounter;
	_idCounter++;
	_isVisible = true;
	_parent = nullptr;

}

component::component(int x, int y) :component()
{
	setX(x);
	setY(y);
}

component::component(int x, int y, int width, int height) :component(x, y)
{
	setWidth(width);
	setHeight(height);

}

void component::move(int dx, int dy)
{
	setX(_x + dx);
	setY(_y + dy);
}

void component::onClick(int x, int y)
{
	cout <<"You clicked on " << getName() <<" id="<< _id << endl;
}

string component::toString()	
{
	string res;
	if (_isVisible) res = "+";
	else res = "-";
	res+= getName() + " id=" + to_string(_id) + " (" + to_string(_x) + "," + to_string(_y)
		+ ") " + to_string(_width) + "*" + to_string(_height);
	if (_parent!=nullptr)
	res+=" par_id=" + to_string(_parent->getId());
	return res;
	
}

string component::getName()
{
	string name= typeid(*this).name();
	return name.substr(6, name.length());
}

int component::getId()
{
	return _id;
}

int component::getX()
{
	return _x;
}

void component::setX(int x)
{
	if (x >= 0) _x = x;
	else throw exception("Illigal value");
}

int component::getY()
{
	return _y;
}

void component::setY(int y)
{
	if (y >= 0) _y = y;
	else throw exception("Illigal value");
}

int component::getWidth()
{
	return _width;
}

void component::setWidth(int width)
{
	if (width >= 0) _width = width;
	else throw exception("Illigal value");
}

int component::getHeight()
{
	return _height;
}

void component::setHeight(int height)
{
	if (height >= 0) _height = height;
	else throw exception("Illigal value");
}

bool component::isClicked(int x, int y)
{
	if (!_isVisible) return false;

	list<int> d = getOffset();
	int dx=d.front();
	int dy=d.back();
	
	return ((x >= (_x + dx)) && (x <= ((_x+dx) + _width))
		&& (y >= (_y + dy)) && (y <= ((_y+dy) + _height)));
}


component::~component()
{
}

list<int> component::getOffset()
{
	list<int> d;
	int dx = 0;
	int dy = 0;
	d.emplace_front(dx);
	d.emplace_back(dy);

	component* root = _parent;
	if (root == nullptr) return d;
	else {
		d.emplace_front(d.front() + root->_x);
		d.emplace_back(d.back() + root->_y);
	}

	while (1) {
		if (root->_parent != nullptr) {
			root = root->_parent;
			d.emplace_front(d.front()+root->_x);
			d.emplace_back(d.back() + root->_y);
		}
		else break;
	}
	return d;
}