#include "group.h"

int Group::CountList()
{
	int result = 0;
	ListGroup *temp = this->last;
	for (; temp != NULL; result++)
	{
		temp = temp->next;
	}
	return result;
}

bool Group::CheckIndex(int index)
{
	return (index > 0) && (index <= this->CountList());
}

Group::Group()
{
	this->last = NULL;
}

Group::~Group()
{
}

void Group::Add(List *_list)
{
	ListGroup *temp = new ListGroup();
	temp->list = _list;
	temp->next = this->last;
	this->last = temp;
}

void Group::AddNew()
{
	this->Add(new List());
}

List *Group::Get(int index)
{
	if (this->CheckIndex(index))
		throw Exception(Exception::Code::WrongListIndex, index);
	ListGroup *result = NULL;
	if (this->last != NULL) {
		result = this->last;
		index--;
		while ((index > 0) && (result != NULL))
		{
			result = result->next;
			index--;
		}
	}
	else
	{
		throw Exception(Exception::Code::NoListFounded);
	}
	return result->list;
}

void Group::Print()
{
	if (this->last == NULL)
		throw Exception(Exception::Code::NoListFounded);
	ListGroup *temp = this->last;
	for (int i = 0; temp != NULL; i++, temp = temp->next)
	{
		cout << " List #" << i << endl;
		cout << *(temp->list) << endl;
	}
}

void Group::Delete(int index)
{
	if (this->CheckIndex(index))
		throw Exception(Exception::Code::WrongListIndex);
	if (this->last != NULL) {
		if (index == 1)
			this->last = this->last->next;
		ListGroup *temp = this->last;
		ListGroup *prevTemp = NULL;
		index--;
		for (; (temp != NULL) && (index > 0); index--)
		{
			prevTemp = temp;
			temp = temp->next;
		}
		if (prevTemp != NULL)
		{
			prevTemp->next = temp->next;
		}
		delete (temp->list);
	}
	else
	{
		throw Exception(Exception::Code::NoListFounded);
	}
}

void Group::HandleEvent(Event *)
{
}
