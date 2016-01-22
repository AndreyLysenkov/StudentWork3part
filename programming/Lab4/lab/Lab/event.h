#pragma once
#include "group.h"

struct MethodList
{
	Method *method;
	MethodList *next;
};

class Event
{
	int command;
	bool isValid;
public:
	MethodList *methodList;
	Event();
	int GetCommand();
	bool IsValid();
	void Clear();
	void Add(Method*);
	void Get();
};

class Constant
{
public:
	enum Group
	{
		Trial = 0,
		Exam = 1,
		FinalExam = 2,
		Test = 3
	};
	enum Command
	{
		Exit = 0,
		Print = 1,
		Add = 2,
		Delete = 3,
		ForEach = 4
	};
};