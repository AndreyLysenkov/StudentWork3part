#pragma once
#include "group.h"

class Event
{
	int command;
	void PrintMenu(int, char*);
	bool CheckGroupIndex(int);
public:
	static Constant constant;
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

static class Constant {
private:
	static int COMMAND_SHIFT;
public:
	
	static int BuildCommand(int, int);

	static void UnbuildCommand(int, int&, int&);
	
	enum Group
	{
		Exit = 0,
		Trial = 1,
		Exam = 2,
		FinalExam = 3,
		Test = 4
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