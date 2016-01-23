#pragma once
#include "group.h"

class Event
{
	const int COMMAND_SHIFT = 8;
	int command;
	void PrintMenu(int, char*);
	bool CheckGroupIndex(int);
public:
	struct MethodList
	{
		Method method;
		MethodList *next;
	};
	MethodList *methodList;
	Event();
	int GetCommand();
	bool IsValid();
	void Clear();
	void Add(Method);
	void Get();
};

class Constant
{
public:
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
};