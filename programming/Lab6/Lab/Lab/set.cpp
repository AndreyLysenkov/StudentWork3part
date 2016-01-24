#include "set.h"

template<class Value>
Set<Value>::Set()
{
	last = NULL;
}

template<class Value>
Set<Value>::Set(Value item1, ...)
{
	Value *item = &item1;
	while (item != NULL)
	{
		*this + item;
		item++;
	}
}

template<class Value>
Set<Value>::~Set()
{
}

template<class Value>
Set<Value>& Set<Value>::operator=(const Set<Value>& set)
{
	this->last = NULL;
	Item *temp = set.GetLast();
	while (temp != NULL)
	{
		*this + temp->value;
		temp = temp->next;
	}
	return *this;
}

template<class Value>
void Set<Value>::operator+(Set<Value> set)
{
	Item temp = set.GetLast();
	for (; temp != NULL; temp = temp->next)
	{
		*this + temp->value;
	}
}

template<class Value>
void Set<Value>::operator+(Value _value)
{
	if (!IsBelong(_value))
	{
		Item *temp = new Item();
		temp->value = _value;
		temp->next = last;
		last = temp;
	}
}

template<class Value>
Set<Value>* Set<Value>::operator*(Set<Value> set)
{
	Set<value> result = new Set<Value>();
	Item *temp = set.GetLast();
	for (; temp != NULL; temp = temp -> next)
	{
		if (this->IsBelong(temp->value))
		{
			*result + temp->value;
		}
	}
	return result;
}

template<class Value>
bool Set<Value>::operator<=(const Set<Value>& set)
{
	return (set.IsSubSet(this));
}

template<class Value>
const bool Set<Value>::IsBelong(Value value)
{
	Item *temp = this->last;
	for (; temp != NULL; temp = temp->next)
	{
		if (temp->value == value)
		{
			return true;
		}
	}
	return false;
}

template<class Value>
const Item Set<Value>::GetLast()
{
	return this->last;
}

template<class Value>
void Set<Value>::Print()
{
	Item *temp = last;
	cout << "\n >> Set of " << typeid(Value).name() << " ";
	for (; temp != NULL; temp = temp->next)
	{
		cout << "; " << temp->value;
	}
}

template<class Value>
const bool Set<Value>::IsSubSet(const Set<Value> set)
{
	Item *temp = set.GetLast();
	while (temp != NULL)
	{
		if (!IsBelong(temp->value))
		{
			return false;
		}
		temp = temp->next;
	}
	return true;
}
