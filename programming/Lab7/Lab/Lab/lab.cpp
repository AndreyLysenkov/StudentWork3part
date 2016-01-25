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

void Task1()
{
	set<int> set1, set2;
	set<int>::iterator i;
	int temp = 0;
	srand(time(0));

	int size1 = 5 + rand() % 5;
	cout << "Filling set1 : ";
	for (int j = 0; j < size1; j++)
	{
		temp = rand() % 27;
		set1.emplace(temp);
		cout << temp << " ";
	}
	set1.emplace(2713);
	set1.emplace(-5);
	PrintSet(&set1);
	cout << "enter number to erase (enter not number for exit): ";
	do
	{
		cout << "\n > ";
		cin >> temp;
		if (cin.fail())
			set1.erase(temp);
	} while (!cin.fail());
	PrintSet(&set1);

	int size2 = 3 + rand() % 10;
	cout << "Filling set2 : ";
	for (int j = 0; j < size2; j++)
	{
		temp = rand() % 27;
		set2.emplace(temp);
		cout << temp << " ";
	}
	PrintSet(&set2);

	


}

//	fmap1.erase('d');
//	cout << " Erased key 'd' and replaced all values >50 by neg(value):";
//	for (i = fmap1.begin(); i != fmap1.end(); i++)
//	{
//		if (i->second > 50)
//		{
//			i->second = -(i->second);
//		}
//	}
//	PrintMultimap(fmap1);
//
//	cout << "\n Second multimap:";
//	for (char ch = 'c'; ch <= 'i'; ch++)
//	{
//		fmap2.insert(pair<char, float>(ch, (1 + rand() % 42) * 1.893));
//	}
//	fmap2.insert(pair<char, float>('c', 987.654));
//	PrintMultimap(fmap2);
//
//	cout << "\n Current first:";
//	PrintMultimap(fmap1);
//	cout << " type float: ";
//	float value;
//	cin >> value;
//	cout << " type int n: ";
//	int n;
//	cin >> n;
//	cout << "\n Removed " << n << " elements after value " << value << " (if possible):";
//	i = fmap1.begin();
//	while (i != fmap1.end() && i->second != value)
//	{
//		i++;
//	}
//	if (i != fmap1.end())
//	{
//		i++;
//	}
//	while (n > 0 && i != fmap1.end())
//	{
//		fmap1.erase(i++);
//		n--;
//	}
//	PrintMultimap(fmap1);
//
//	for (i = fmap2.begin(); i != fmap2.end(); i++)
//	{
//		fmap1.insert(pair<char, float>(i->first, i->second));
//	}
//	cout << "\n First after merge:";
//	PrintMultimap(fmap1);
//	cout << "\n Second:";
//	PrintMultimap(fmap2);
//
//	system("pause");
//}



int main()
{
	cout << "Starting task1...\n";
	Task1();

	//set<Test> _tmp;
	//for (int i = 0; i < 10; i++)
	//{
	//	_tmp.emplace(Test(i + 5, 100 - i * 3));
	//}
	//set<int> op;
	//op.insert(5);
	//op.insert(6);
	//PrintSet(&_tmp);
	//PrintSet(&op);

	//stack<int> ch;
	//ch.push(5);
	//for (int i = 0; i < 10; i++)
	//	ch.push(13 - i*2);
	//PrintStack(&ch);
	
	system("pause");
	return 0;
}