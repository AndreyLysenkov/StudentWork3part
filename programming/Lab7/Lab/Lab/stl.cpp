#include "user.h"
#include <set>
//#include <iterator>
using namespace std;

template <class Value>
void PrintSet(set<Value> *_set)
{
	cout << "\nSet of " << typeid(Value).name() << "[";
	set<Value>::iterator i = (*_set).begin();
	for (; i != (*_set).end(); ++i)
	{
		cout << (*i) << ", ";
	}
	cout << endl << endl;
	cout << "]\n";
}

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
