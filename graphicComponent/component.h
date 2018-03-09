#pragma once
#include <string>
#include <list>

using namespace std;
class component
{
private:
	static int _idCounter;
	list<int> getOffset();
protected:
	int _id;
	int _width;
	int _height;
	int _x;
	int _y;
public:
	component();
	component(int x, int y);
	component(int x, int y, int width, int height);
	~component();
	bool _isVisible;
	component* _parent;
	void move(int x, int y);
	bool isClicked(int x, int y);
	virtual void onClick(int x, int y) = 0;
	string toString();
	string getName();
	int getId();
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	int getWidth();
	void setWidth(int width);
	int getHeight();
	void setHeight(int height);
};