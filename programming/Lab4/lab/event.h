#pragma once

struct MethodList
{
	Method method;
	MethodList *next;
};

class Event
{
	int command;
	bool isValid;
public:
	MethodList *method;
	Event();
	int GetCommand();
	bool IsValid();
	void Clear();
	void Add();
	void Get();
};