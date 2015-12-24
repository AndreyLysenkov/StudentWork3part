#pragma once
#include "trial.h"
using namespace std;

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

struct Element
{
	Trial *obj;
	Element *next;
};