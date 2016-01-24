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

//template <class T>
//Set<T>& Set<T>::operator=(const Set<T>& p_other)
//{
//	Item<T> *p_temp = p_other.last;
//	if (p_temp)
//	{
//		this->last = new Item<T>;
//		this->last->data = p_temp->data;
//		this->last->next = NULL;
//		p_temp = p_temp->next;
//		Item<T> *temp = this->last;
//		while (p_temp)
//		{
//			temp->next = new Item<T>;
//			temp = temp->next;
//			temp->data = p_temp->data;
//			temp->next = NULL;
//			p_temp = p_temp->next;
//		}
//	}
//	return *this;
//}

template<class Value>
Set<Value>& Set<Value>::operator=(const Set<Value>& set)
{
	
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
bool Set<Value>::operator<=(const Set<Value>&)
{
	return false;
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



//template <class T>
//Set<T>::operator int()
//{
//	int count = 0;
//	Item<T> *temp = last;
//	while (temp)
//	{
//		count++;
//		temp = temp->next;
//	}
//	return count;
//}