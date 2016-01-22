#pragma once
#include "event.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

Event::Event()
{
	isValid = false;
	methodList = NULL;
}

int Event::GetCommand()
{
	return command;
}

bool Event::IsValid()
{
	return isValid;
}

void Event::Clear()
{
	isValid = false;
}

void Event::Add(Method _method)
{
	MethodList *tmp = new MethodList;
	tmp->method = _method;
	tmp->next = methodList;
	methodList = tmp;
}

void Event::PrintMenu(int menu, char* message)
{
	cout << " >" << menu << " - " << message << endl;
}

bool Event::CheckGroupIndex(int index)
{
	return (index >= 0) && (index <= 4)
}

void Event::Get()
{
	int group = grTrial;
	int command = cmExit;

	do
	{
		cout << "   ---Action---" << endl;
		PrintMenu(cmPrint, "Print\0");
		PrintMenu(cmAdd, "Add\0");
		PrintMenu(cmDelete, "Delete\0");
		PrintMenu(cmForEach, "ForEach\0");
		PrintMenu(cmExit, "Exit\0");
		cout << endl;
		cout << " >";
		cin >> command;

		do
		{
			if (command != cmExit)
			{
				cout << "   ---Group---" << endl;
				PrintMenu(gTrial, "Trial\0");
				PrintMenu(grExam, "Exam\0");
				PrintMenu(grFinalExam, "FinalExam\0");
				PrintMenu(grTest, "Test\0");
				PrintMenu(grExit, "Exit\0");
				cout << endl;
				cout << " >";
				cin >> group;
			}
		} while (CheckGroupIndex(group));
	


	} while (command != cmExit);

}

//void Event::GetEvent()
//{
//	do
//	{
//			while (gr != grMonarchy && gr != grKingdom && gr != grRepublic && gr != cmBack)
//			{
//				cout << " incorrect number, enter number again\n> ";
//				cin >> gr;
//			}
//			isBack = gr == cmBack;
//			gr = gr * SHIFT + cm;
//		}
//		else
//		{
//			if (cm == cmExit)
//			{
//				isBack = false;
//				gr = cmExit;
//			}
//		}
//	} while (isBack);
//
//	isValid = true;
//	command = gr;
//}
