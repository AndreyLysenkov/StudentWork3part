#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int user = 0;

void PrintPassed(Trial *obj)
{
	Test *work = dynamic_cast<Test*>(obj);
	if (work->GetScore() > work->GetMinScore())
	{
		work->Print();
	}
}

void PrintGreater(Trial *obj)
{
	Test *work = dynamic_cast<Test*>(obj);
	if (work->GetScore() > user)
	{
		work->Print();
	}
}

int main()
{
	TestGroup group(new Test("Math", "1st half", 65, 100, 20));
	group.Add(new Test("Prog", "13 test", 75, 100, 20));
	group.Add(new Test("Math", "27 test", 30, 100, 20));
	group.Add(new Test("Phisics", "0 test", 10, 100, 20));
	group.Show();
	cout << "-- All who passed: " << endl;
	Method method = PrintPassed;
	group.ForEach(method);
	cout << endl << "-- Enter min one:";
	cin >> user;
	cout << endl;
	Method method0 = PrintGreater;
	group.ForEach(method0);
	system("pause");
}