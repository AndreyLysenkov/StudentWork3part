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
	Set(Value, ...);
	~Set();
	Set<Value>& operator = (const Set<Value>&);
	void operator + (Set<Value>);
	Set<Value>* operator * (Set<Value>);
	bool operator <= (const Set<Value>&, const Set<Value>&);

	bool IsBelong(Value);
	void Print();
private:
	Item *last;
};