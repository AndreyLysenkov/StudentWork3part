#include "stl.cpp"

//Task
//� ��������� � 1 ��������� ��������� :
//1. ������� ������ - ��������� � ������������ � ��������� ������� � ��������� ��� �������, ��� ������� ������������ ��������� �������.
//2. ����������� ���������.
//3. �������� ���������, ������ �� ���� ���� �������� � ������� ������.
//4. ����������� ���������, ��������� ��� ������� � ��� ��������� ���������.
//5. ������� ������ ��������� ����� �� ������ � ��������� ��� ������� ���� �� ����, ��� � ������ ���������.
//6. �������� ������ ���������, ������ �� ���� n ��������� ����� ��������� � ������� ����� � ���� ��� �������� �� ������� ����������.
//7. ����������� ������ � ������ ����������.
//� ��������� � 2 ��������� �� �� �����, �� ��� ������ ����������������� ����.
//� ��������� � 3 ��������� ��������� :
//1. ������� ���������, ���������� ������� ����������������� ����.��� ���������� ���������� � ������������ � ��������� �������.
//2. ������������� ��� �� �������� ���������.
//3. ����������� ���������.
//4. ��������� ���������� ��������, ����� � ���������� �������, ��������������� ��������� �������.
//5. ����������� ��������, ��������������� ��������� ������� � ������(�������������� ������) ���������.��� ������� ���������� ������������ ��������� �������.
//6. ����������� ������ ���������.
//7. ������������� ������ � ������ ���������� �� ����������� ���������.
//2
//8. ����������� ��.
//9. �������� ������ ��������� ����� ������� ������ ����.
//10. ����������� ������ ���������.
//11. ����������, ������� ���������, ��������������� ��������� �������, �������� ������ ���������.
//12. ����������, ���� �� � ������� ���������� �������, ��������������� ��������� �������.
//Variant 9
//9 - set - stack - int

//#include <iostream>
//#include <vector>
//using namespace std;
//
//void main()
//{
//	vector<int> v;
//	int i;
//	for (i = 0;i<10;i++)v.push_back(i);
//	cout << "size = " << v.size() << "\n";
//	for (i = 0;i<10;i++)cout << v[i] << " ";
//	cout << endl;
//	for (i = 0;i<10;i++)v[i] = v[i] + v[i];
//	for (i = 0;i<v.size();i++)cout << v[i] << " ";
//	cout << endl;
//	system("pause");
//}

int main()
{
	set<Test> _tmp;
//	//_tmp.insert(1, 5);
//	/*_tmp.emplace(1);*/
//	//_tmp.emplace(2);
//	//_tmp.insert(30);
	for (int i = 0; i < 10; i++)
	{
		_tmp.emplace(Test(i, i * 3 + 3));
	}
//	Test x = Test(2, 2 * 3 + 3);
//	Test y = Test(3, 3 * 3 + 3);
//	_tmp.insert(x);
//	_tmp.emplace(y);
//	copy(_tmp.begin(), 
//		_tmp.end(), 
//		ostream_iterator<Test>(cout, " "));
//
	set<int> op;
//
	op.insert(5);
	op.insert(6);
//	copy(op.begin(),
//		op.end(),
//		ostream_iterator<int>(cout, " "));
//
//	set<Test>::iterator p = _tmp.begin();
//	//while (p != _tmp.end())
//	//{
//	//	cout << *p << " ";
//	//	p++;
//	//}
	PrintSet(&_tmp);
	PrintSet(&op);
//	/*
//	vector<int>::iterator p=v.begin();
//	while(p!=v.end())
//	{cout<<*p<<� �;p++;}
//	}
//	for (i = 0;i<10;i++)v.push_back(i);
//	cout << �size = � << v.size() << �\n�;
//	vector<int>::iterator p = v.begin();*/
//	//while (p != v.end())
//	//{
//	//	cout << *p << � �;p++;
//	//}
//	//fmap1.insert(pair<char, float>('c', 987.654));
	system("pause");
	return 0;
}

//#include <iostream>
//#include <set>
//
//using namespace std;
//
//class term {
//public:
//	string name;
//	int p;
//	term(string _name, int _p) : name(_name), p(_p) {};
//	bool operator< 
//(const term& b) const {
//		return name < b.name;
// } };
//int main(int argv, char **args) {
//	std::set<term> data;
//	data.insert(term("hello", 4));
//	data.insert(term("test", 1));
//	data.insert(term("anywhere", 2));
//	data.insert(term("two-fold", 7));
//	data.insert(term("nothing", 42));
//	for (std::set<term>::const_iterator it = data.begin();it != data.end();it++) {
//		std::cout << ", " << it->p << std::endl;
//	}
//	system("pause");
//}

