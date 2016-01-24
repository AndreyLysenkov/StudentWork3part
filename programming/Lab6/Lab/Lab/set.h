#pragma once

template <class Value>
class Set
{
public:
	struct Item
	{
		Value value;
		Item *next;
	};
	Set();
	~Set();
	Set<Value>& operator = (const Set<Value>&);
	void operator + (Value);
	Set<Value>* operator * (Set<value>);
	bool IsBelong(Value);
	void Print();
private:
	Item *last;
};


//	Set<T>* operator*(Set<T>);
//	operator int();