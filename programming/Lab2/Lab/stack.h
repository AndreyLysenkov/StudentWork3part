#pragma once
#include "objects.h"
using namespace std;

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