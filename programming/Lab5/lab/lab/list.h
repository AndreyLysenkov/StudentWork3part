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
	List& operator=(List&);
	static void operator+(List, char);
	void operator--();
	bool operator!=(List);
	friend ostream& operator<<(ostream&, List&);
	friend istream& operator<<(istream&, List&);
	~List();
};
//
//class List
//{
//private:
//	ListElement *last;
//	int size;
//public:
//	List();
//	List& operator=(List&);
//	void operator+(char);
//	void operator--();
//	bool operator==(List);
//	friend ostream& operator<<(ostream&, List&);
//	friend istream& operator>>(istream&, List&);
//	int GetSize();
//	void Print();
//	void Input();
//};
