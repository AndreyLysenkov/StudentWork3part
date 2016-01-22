#pragma once
#include "stdafx.h"
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

void Event::Add(Method *_method)
{
	MethodList *tmp = new MethodList;
	tmp->method = _method;
	tmp->next = methodList;
	methodList = tmp;
}

void Event::Get()
{
	Constant.Group group;
	//Constant.Command command;
}



//void Event::GetEvent()
//{
//	int gr;
//	int cm;
//	bool isBack = true;
//
//	do
//	{
//		cout << "\n\n Choose action:\n\n";
//		cout << " " << cmAdd << " - Add\n";
//		cout << " " << cmDelete << " - Delete\n";
//		cout << " " << cmPrint << " - Print\n";
//		cout << " " << cmForeach << " - Foreach\n";
//		cout << " " << cmExit << " - Exit\n\n> ";
//
//		cin >> cm;
//
//		if (cm == cmAdd || cm == cmPrint || cm == cmDelete || cm == cmForeach)
//		{
//			cout << "\n\n Choose group: \n\n";
//			cout << " " << grMonarchy << " - Monarchy\n";
//			cout << " " << grKingdom << " - Kingdom\n";
//			cout << " " << grRepublic << " - Republic\n";
//			cout << " " << cmBack << " - Back\n\n> ";
//
//			cin >> gr;
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
