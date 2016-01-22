#pragma once
#include "group.h"

class Event
{
	int command;
	bool isValid;
	void PrintMenu(int, char*);
	bool CheckGroupIndex(int);
public:
	struct MethodList
	{
		Method method;
		MethodList *next;
	};
	enum constGroup
	{
		grExit = 0,
		grTrial = 1,
		grExam = 2,
		grFinalExam = 3,
		grTest = 4
	};
	enum constCommand
	{
		cmExit = 0,
		cmPrint = 1,
		cmAdd = 2,
		cmDelete = 3,
		cmForEach = 4
	};
	MethodList *methodList;
	Event();
	int GetCommand();
	bool IsValid();
	void Clear();
	void Add(Method);
	void Get();
};