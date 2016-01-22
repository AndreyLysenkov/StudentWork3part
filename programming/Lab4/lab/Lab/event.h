#pragma once
#include "group.h"

class Event
{
	int command;
	bool isValid;
public:
	struct MethodList
	{
		Method method;
		MethodList *next;
	};
	enum Group
	{
		grTrial = 0,
		grExam = 1,
		grFinalExam = 2,
		grTest = 3
	};
	enum Command
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