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
	int _group = Constant::Group::Trial;
	int _command = Constant::Command::Exit;

	do
	{
		cout << "   ---Action---" << endl;
		PrintMenu(Constant::Command::Print, "Print\0");
		PrintMenu(Constant::Command::Add, "Add\0");
		PrintMenu(Constant::Command::Delete, "Delete\0");
		PrintMenu(Constant::Command::ForEach, "ForEach\0");
		PrintMenu(Constant::Command::Exit, "Exit\0");
		cout << endl;
		cout << " >";
		cin >> _command;

		if (_command != Constant::Command::Exit)
		{

			do
			{
				if (_command != Constant::Command::Exit)
				{
					cout << "   ---Group---" << endl;
					PrintMenu(Constant::Group::Trial, "Trial\0");
					PrintMenu(Constant::Group::Exam, "Exam\0");
					PrintMenu(Constant::Group::FinalExam, "FinalExam\0");
					PrintMenu(Constant::Group::Test, "Test\0");
					PrintMenu(Constant::Group::Exit, "Exit\0");
					cout << endl;
					cout << " >";
					cin >> _group;
				}
			} while (CheckGroupIndex(_group));

			command = Constant::BuildCommand(_command, _group);
		}

	} while (_command != Constant::Command::Exit);
}

int Constant::COMMAND_SHIFT = 8;

int Constant::BuildCommand(int menu, int group)
{
	return menu * COMMAND_SHIFT + group;
}

void Constant::UnbuildCommand(int command, int &menu, int &group)
{
	menu = command / COMMAND_SHIFT;
	group = command % COMMAND_SHIFT;
}