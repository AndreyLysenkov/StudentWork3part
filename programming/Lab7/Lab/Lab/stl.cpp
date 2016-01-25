#include "user.h"
#include <set>
#include <stack>
#include <iterator>
#include <time.h>
using namespace std;

template <class Value>
void PrintSet(set<Value> *_set)
{
	cout << "\nSet of " << typeid(Value).name() << "[";
	set<Value>::iterator i = (*_set).begin();
	for (int j = 1; i != (*_set).end(); ++i, j++)
	{
		cout << (*i);
		if (j < (*_set).size())
			cout << ", ";
	}
	cout << "]\n";
}

template <class Value>
void PrintStack(stack<Value> *_stack)
{
	cout << "\nStack of " << typeid(Value).name() << ":\n[";
	Value i = (*_stack).top();
	for (int j = 0; j != (*_stack).size(); ++i, j++)
	{
		cout << (i);
		if (j < (*_stack).size() - 1)
			cout << ", ";
	}
	cout << "]\n";
}