#include "event.h"
#include "group.h"
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
		
	Method action1 = PrintPassed;
	Method action2 = PrintGreater;
	cout << endl << "-- Enter min one:";
	cin >> user;
	Event *_event = new Event();
	_event->Add(*action1);
	_event->Add(*action2);

	int cmd = Constant::Command::cmExit;
	do
	{
		_event->Get();
		cmd = _event->GetCommand();
		group.HandleEvent(_event);
	} while (cmd != Constant::Command::cmExit);

	cout << " --- Press Enter ---";
	system("pause");
}