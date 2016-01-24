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
		Copy = 4,
		Delete = 5,
		Compare = 6,
		Print = 7,
		Exit = 0,
		Undefinded = 0
	};
	Event();
	~Event();
	void Clear();
	bool IsValid();
	int GetCommand();
	void Create(int);
};