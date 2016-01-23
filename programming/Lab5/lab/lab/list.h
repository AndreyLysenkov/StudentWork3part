#pragma once
#include <iostream>
using namespace std;

struct Element
{
	Element *next;
	char symbol;
};

class List
{
	Element *last;
public:
	List();
	~List();
	List& operator=(List&);
	void operator+(char);
	void operator--();
	bool operator!=(List);
	friend ostream& operator<<(ostream&, List&);
	friend istream& operator<<(istream&, List&);
	void Print();
	void Input();
	Element *GetLast();
};