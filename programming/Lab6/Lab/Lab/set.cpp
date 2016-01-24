#include "set.h"

template<class Value>
Set<Value>::Set()
{
}

template<class Value>
Set<Value>::Set(Value, ...)
{
}

template<class Value>
Set<Value>::~Set()
{
}

template<class Value>
Set<Value>& Set<Value>::operator=(const Set<Value>&)
{
	// TODO: вставьте здесь оператор return
}

template<class Value>
void Set<Value>::operator+(Set<Value>)
{
}

template<class Value>
Set<Value>* Set<Value>::operator*(Set<Value>)
{
	return nullptr;
}

template<class Value>
bool Set<Value>::operator<=(const Set<Value>&)
{
	return false;
}

template<class Value>
bool Set<Value>::IsBelong(Value)
{
	return false;
}

template<class Value>
void Set<Value>::Print()
{
}
