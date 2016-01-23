#pragma once


class Event
{
public:
	enum Command
	{
		Create = 1,
		Add = 6,
		Copy = 2,
		Delete = 3,
		Print = 4,
		Compare = 5,
		Exit = 0
	};
	Event();
	~Event();
	void Clear();
	void IsValid();
	int GetCommand();
	void Create(int);
};