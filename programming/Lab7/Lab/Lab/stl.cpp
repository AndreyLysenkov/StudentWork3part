#include "user.h"
#include <set>
#include <stack>
#include <iterator>
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

//
//std::vector<int> v;
//while (!s.empty())
//{
//	if (s.top() != 5)                // Это ключевой момент, в стек помещаются
//		v.push_back(s.top());   // все элементы не равные 5
//
//	s.pop();
//}
//
//// Для проверки выведем стек на экран
//while (!s.empty()) {
//	std::cout << s.top() << ' ';
//	s.pop();
//}


//template <class TD>
//void PrintDeque(TD p_deque)
//{
//	cout << "\n\n";
//	for (int i = 0; i
//< p_deque.size(); i++)
//	{
//		cout << p_deque[i]
//<< endl;
//	}
//}
//template <class TM>
//void PrintMultimap(TM p_map)
//{
//	cout << "\n\n";
//	TM::iterator i;
//	for (i = p_map.begin();
//i != p_map.end(); i++)
//	{
//		cout << "\tpair <"
//<< (*i).first << " : " 
//<< (*i).second << ">\n";
//	}
//	cout << endl;
//}
//
