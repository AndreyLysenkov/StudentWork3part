#pragma once
#include "list.h"
#include "event.h"
#include "exception.h"

class Group
{
private:
	struct ListGroup
	{
		List *list;
		ListGroup *next;
	};
	ListGroup *last;
	int CountList();
	bool CheckIndex(int);
public:
	Group();
	~Group();
	void Add(List*);
	void AddNew();
	List* Get(int);
	void Print();
	void Delete(int);
	void HandleEvent(Event*);
};