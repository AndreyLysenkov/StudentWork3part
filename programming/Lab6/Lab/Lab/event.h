#pragma once
#include "menu.h"

enum Command
{
	Add1 = 1,
	Add2 = 2,
	Add = 3,
	Multy = 4,
	Compare = 5,
	Print = 6,
	Exit = 0,
	Undefinded = 0
};

class Event
{
private:
	int command;
	static int COMMAND_SHIFT;
	void SetCommand(int);
	static bool CheckCommand(int);
public:
	Event();
	~Event();
	void Clear();
	bool IsValid();
	int GetCommand();
	int GetType();
	void Create(int, int = 0);
};