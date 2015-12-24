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
	static Element *top;
	Stack();
	Stack(Trial*);
	~Stack();
	void Add(Trial*);
	Trial *Get();
	static void Show();
};