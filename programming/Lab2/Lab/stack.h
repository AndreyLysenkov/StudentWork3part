#pragma once
#include <iostream>
#include "trial.h"
using namespace std;

class Stack
{
protected:
	static Element *top;
public:
	Stack();
	Stack(Trial*);
	~Stack();
	void Add(Trial*);
	Trial *Get();
	Element *GetTop();
	static void Show();
};

class Element
{
protected:
	Trial *obj;
	Element *next;
public:
	Element(Trial*, Element*);
	~Element();
	Trial *GetObj();
	Element *GetNext();
	bool isLast();
};