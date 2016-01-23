#pragma once
#include "exception.h"

class Event
{
private:
	int command;
	void SetCommand(int);
	static bool CheckCommand(int);
public:
	enum Command
	{
		Create = 1,
		Add = 2,
		Remove = 3,
		Copy = 3,
		Delete = 4,
		Compare = 6,
		Print = 7,
		Exit = 0,
		Undefinded = -1
	};
	Event();
	~Event();
	void Clear();
	bool IsValid();
	int GetCommand();
	void Create(int);
};