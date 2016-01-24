#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

template <typename Value>
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
	Set<Value> operator + (Set<Value>);
	void operator + (Value);
	Set<Value>* operator * (Set<Value>);
	bool operator <= (const Set<Value>&);
	const bool IsBelong(Value);
	const Item GetLast();
	const bool IsSubSet(Set<Value>);
	void Print();
private:
	Item *last;
};