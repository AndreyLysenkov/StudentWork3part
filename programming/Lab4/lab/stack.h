#pragma once
#include "objects.h"

struct Element
{
	Trial *obj;
	Element *next;
};

class Stack
{
public:
	Element *top;
	Stack();
	Stack(Trial*);
	~Stack();
	void Add(Trial*);
	Trial *Get();
	void Show();
};