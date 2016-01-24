#pragma once
//include "exception.h"

enum Command
{
	Add1 = 1,
	Add2 = 2,
	Add = 3,
	Multy = 4,
	Compare = 5,
	Print = 6,
	Exit = 0
};


class Event
{
private:
	int command;
	void SetCommand(int);
	static bool CheckCommand(int);
public:
	Event();
	~Event();
	void Clear();
	bool IsValid();
	int GetCommand();
	void Create(int);
};