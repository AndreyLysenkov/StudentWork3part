#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack()
{
	top = NULL;
}

Stack::Stack(Trial *_obj)
	:Stack()
{
	Element *tmp = new Element(_obj, top);
	top = tmp;
}

Stack::~Stack()
{

}

void Stack::Add(Trial *_obj)
{
	Element *tmp = new Element(_obj, top);
	top = tmp;
}

Trial *Stack::Get()
{
	Trial *tmp = top->GetObj();
	top = top->GetNext();
	return tmp;
}

void Stack::Show()
{
	Element *tmp = top;
	do
	{
		cout << "Element stack: " << &tmp;
		tmp->GetObj()->Print();
		tmp = tmp->GetNext();
	} while (tmp->isLast());
	cout << "end" << endl;
}