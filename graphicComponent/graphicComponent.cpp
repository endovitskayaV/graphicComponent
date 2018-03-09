// graphicComponent.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "component.h"
#include "complexComponent.h"
#include "window.h"
#include "panel.h"
#include "button.h"
#include "line.h"
#include <iostream>
#include <stdlib.h>
using namespace std; 

static window *rootWindow;
static int depth=0;
void add(string str);
void click(string str);
void showAll(string str);
void move(string str);
string blank();
void toString(component* c);
int find(string str, char ch);
bool isComplexComponent(component* c);

int main()
{
    rootWindow = new window(0, 0, 120, 70);
	rootWindow->_isVisible = true;
	rootWindow->title = "Form";

	cout << "GRAPHIC COMPONENT\nEnter\n"
		<< "->add-<type>-parent_id to add new component\n"
		<< "->click-x-y to click on component\n"
		<< "->move-comp_id-dx-dy to move component\n"
		<< "->all to show all components"
		<<"->e to exit\n"
		<< " types:\n w - window, p - panel, l-line, b- button\n"
		<<">";

	string str="";
	cin >> str;
	while (1) {
		switch(str[0]) {
		case 'a':
			switch (str[1]) {
			case 'd': add(str); break;
			case 'l': showAll(str); break;
			}
			break;
		case'c': 
			click(str); break;
		case'm':
			move(str); 
			break;
		case'e': exit(0);
		default: cout << "wrong command";
		}

		cout << ">";
		cin >> str;
	}
    return 0; 
}

void add(string str) {
	if (str.substr(0, 3)._Equal("add")) {
		try {
		component* c;
		switch (str[4]) {
		case 'w': c = new window(); break;
		case'p': c = new panel(); break;
		case'b':  c = new button(); break;
		case'l': c = new line(); break;
		default: {cout << "wrong command";  return; }
		}

		
			int par_id = stoi(str.substr(6, str.size() - 1));
			if (isComplexComponent(rootWindow->findChildById(par_id)))
			((complexComponent*)rootWindow->findChildById(par_id))->addComponent(c);
			else {
				cout << "component with id does not exist or it can not contain components\n";
				return;
			}
		string input;
		cout << "x= [int/-] ";
		cin >> input;
		if (!input._Equal("-")) c->setX(stoi(input));

		cout << "y= [int/-] ";
		cin >> input;
		if (!input._Equal("-")) c->setY(stoi(input));

		cout << "width= [int/-] ";
		cin >> input;
		if (!input._Equal("-")) c->setWidth(stoi(input));

		cout << "height= [int/-] ";
		cin >> input;
		if (!input._Equal("-")) c->setHeight(stoi(input));

		cout << "is visible? [y/n] ";
		cin >> input;
		if (input._Equal("n")) c->_isVisible = false;

		cout << "added\n";
		}catch (exception e) {
			cout << "wrong command";
		}
	}else cout << "wrong command";

}

void click(string str) {
	if (str.substr(0, 5)._Equal("click")) {
		try {
			int index = find(str, '-');
			str = str.substr(index+1, str.size());
			index = find(str, '-');
			int x = stoi(str.substr(0,index));
			int y = stoi(str.substr(index+1,str.size()-1));
			rootWindow->onClick(x, y);
		}
		catch(exception e){
			cout << "wrong command";
		}
	}
	else cout << "wrong command";
		
}

void move(string str) {
	if (str.substr(0, 4)._Equal("move")) {
		try {
			int index = find(str, '-');
			str = str.substr(index + 1, str.size());
			index = find(str, '-');
			int id= stoi(str.substr(0, index));

			str = str.substr(index + 1, str.size());
			index = find(str, '-');
			int dx = stoi(str.substr(0, index));

			int dy = stoi(str.substr(index + 1, str.size() - 1));
			(rootWindow->findChildById(id))->move(dx, dy);
			cout << "moved\n";
		}
		catch (exception e) {
			cout << "wrong command";
		}
	}
	else cout << "wrong command";

}

void showAll(string str) {
	depth = 0;
	if (str._Equal("all")) {
		depth += 2;
		cout << rootWindow->toString() << "\n";

		for each (component* c in rootWindow->getComponents())
		{
			toString(c);
		}
	}
	else cout << "wrong command";
}

void toString(component* c) {
	cout << blank()<< c->toString() << "\n";
		if (isComplexComponent(c)) {
			list<component*> list = ((complexComponent*)c)->getComponents();
			depth += 2;
			for each (component* c1 in list)
			{
				toString(c1);
			}
			depth -= 2;
		}
}

string blank() {
	string res = "";
	for (int i = 0; i < depth; i++) {
		res += " ";
	}
	return res;
}

int find(string str, char ch) {
	for (int i = 0; i < str.size(); i++) { 
		if (str[i] == ch) return i; 
	}
	return -1;

}

bool isComplexComponent(component* c) {
	return (!((c->getName())._Equal("button") || (c->getName())._Equal("line")));
}
