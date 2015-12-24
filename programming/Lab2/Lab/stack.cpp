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
	Add(_obj);
}

Stack::~Stack()
{

}

void Stack::Add(Trial *_obj)
{
	Element *tmp = new Element();
	tmp->obj = _obj;
	tmp->next = top;
	top = tmp;
}

Trial *Stack::Get()
{
	Trial *tmp = top->obj;
	top = top->next;
	return tmp;
}

void Stack::Show()
{
	Element *tmp = top;
	while (tmp != NULL)
	{
		cout << "Element stack: " << &tmp;
		tmp->obj->Print();
		tmp = tmp->next;
	}
	cout << "end" << endl;
}