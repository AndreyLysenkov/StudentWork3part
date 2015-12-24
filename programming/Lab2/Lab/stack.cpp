#include "stack.h"

Stack::Stack()
{
	this->top = NULL;
}

Stack::Stack(Trial *_obj)
	:Stack()
{
	Element *tmp = new Element(_obj, this->top);
	this->top = tmp;
}

Stack::~Stack()
{

}

void Stack::Add(Trial *_obj)
{
	Element *tmp = new Element(_obj, this->top);
	this->top = tmp;
}

Trial *Stack::Get()
{
	Trial *tmp = this->top->GetObj();
	this->top = this->top->GetNext();
	return tmp;
}

Element *Stack::GetTop()
{
	return this->top;
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


Element::Element(Trial* _obj, Element* _next)
{
	this->obj = _obj;
	this->next = _next;
}

Element::~Element()
{

}

Trial *Element::GetObj()
{
	return this->obj;
}

Element * Element::GetNext()
{
	return this->next;
}

bool Element::isLast()
{
	return (this->next == NULL);
}