#pragma once
#include "event.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

Event::Event()
{
	command = 0;
	methodList = NULL;
}

int Event::GetCommand()
{
	return command;
}

bool Event::IsValid()
{
	return (command != 0);
}

void Event::Clear()
{
	command = 0;
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
	return ((index >= 0) && (index <= 4));
}

void Event::Get()
{
	int _group = grTrial;
	int _command = cmExit;

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
		cin >> _command;

		if (_command != cmExit)
		{

			do
			{
				if (_command != cmExit)
				{
					cout << "   ---Group---" << endl;
					PrintMenu(grTrial, "Trial\0");
					PrintMenu(grExam, "Exam\0");
					PrintMenu(grFinalExam, "FinalExam\0");
					PrintMenu(grTest, "Test\0");
					PrintMenu(grExit, "Exit\0");
					cout << endl;
					cout << " >";
					cin >> _group;
				}
			} while (CheckGroupIndex(_group));

			command = _command * COMMAND_SHIFT + _group;
		}

	} while (_command != cmExit);
}
