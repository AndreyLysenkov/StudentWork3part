#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

template <class Value>
struct Item
{
	Value value;
	Item *next;
};

template <class Value>
class Set
{
public:
	Set();
	Set(Value, ...);
	~Set();
	Set<Value>& operator = (const Set<Value>&);
	Set<Value>* operator + (Set<Value>);
	void operator + (Value);
	Set<Value>* operator * (Set<Value>);
	bool operator <= (const Set<Value>&);
	const bool IsBelong(Value);
	const Item<Value> GetLast();
	const bool IsSubSet(Set<Value>);
	void Print();
private:
	Item<Value> *last;
};