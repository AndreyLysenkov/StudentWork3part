#include "set.h"

//template <class T>
//Set<T>::Set()
//{
//	last = NULL;
//}
//double f(double n, ...)    //--заголовок с переменным числом параметров
//{
//	double *p = &n;        //--установились на начало списка параметров
//	double sum = 0, count = 0;
//	while (*p)         //--пока аргумент не равен нулю
//	{
//		sum += (*p);         //--суммируем аргумент
//		p++;             //--«перемещаемся на следующий аргумент
//		count++;         //--считаем  количество аргументов
//	}
//	return ((sum) ? sum / count : 0);    //--вычисляем среднее
//}

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



//

//
//
//template <class T>
//void Set<T>::Print()
//{
//	Item<T> *temp = last;
//	cout << "\n Set of " << typeid(T).name() << ":  {";
//	while (temp)
//	{
//		cout << temp->data;
//		temp = temp->next;
//		if (temp)
//		{
//			cout << ", ";
//		}
//	}
//	cout << "}\n\n";
//}
//
//
//template <class T>
//bool Set<T>::IsInSet(T p_value)
//{
//	bool result = false;
//	Item<T> *temp = last;
//	while (temp)
//	{
//		if (p_value == temp->data)
//		{
//			result = true;
//		}
//		temp = temp->next;
//	}
//	return result;
//}
//
//
//template <class T>
//void Set<T>::operator+(T p_value)
//{
//	if (!IsInSet(p_value))
//	{
//		Item<T> *temp = new Item<T>;
//		temp->data = p_value;
//		temp->next = last;
//		last = temp;
//	}
//}
//
//
//
//
//template <class T>
//Set<T>* Set<T>::operator*(Set<T> p_other)
//{
//	Set<T> *result = new Set<T>;
//	Item<T> *temp = this->last;
//	while (temp)
//	{
//		if (p_other.IsInSet(temp->data))
//		{
//			*result + temp->data;
//		}
//		temp = temp->next;
//	}
//	return result;
//}
//
//
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
//
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
//
//
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
