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

void Group::HandleEvent(Event _event)
{
	if (_event.IsValid())
	{
		try {
			switch (_event.GetCommand())
			{
			case (Event::Command::Create) :
			{
				this->AddNew();
				this->Get(1)->Input();
				_event.Clear();
				break;
			}
			case (Event::Command::Add) :
			{
				this->Print();
				cout << endl << " Enter index of list ";
				int index = Menu::Input::Number();
				cout << " Enter symbol (element) ";
				char element = Menu::Input::Char();
				this->Get(index) + element;
				_event.Clear();
				break;
			}
			case (Event::Command::Remove) :
			{
				this->Print();
				cout << endl << " Enter index of list ";
				int index = Menu::Input::Number();
				--*Get(index);
				_event.Clear();
				break;
			}
			case (Event::Command::Copy) :
			{
				this->Print();
				cout << endl << " Enter index of list ";
				int index = Menu::Input::Number();
				this->AddNew();
				*(this->Get(1)) = *(this->Get(index));
				_event.Clear();
				break;
			}
			case (Event::Command::Delete) :
			{
				this->Print();
				cout << endl << " Enter index of list ";
				int index = Menu::Input::Number();
				this->Delete(index);
				_event.Clear();
				break;
			}
			case (Event::Command::Compare) :
			{

				this->Print();
				cout << endl << " Enter index of list1 ";
				int index1 = Menu::Input::Number();
				cout << endl << " Enter index of list2 ";
				int index2 = Menu::Input::Number();
				if (*(this->Get(index1)) != *(this->Get(index2)))
				{
					cout << "Not equal" << endl;
				}
				else
				{
					cout << "Do equal" << endl;
				}
				_event.Clear();
				break;
			}
			case (Event::Command::Print) :
			{
				this->Print();
				_event.Clear();
				break;
			}
			default:
			{break;}
			}
		}
		catch (Exception exception)
		{
			switch (exception.GetCode())
			{
			case (Exception::Code::NoListFounded) :
			{
				cout << exception.GetMessage() << endl;
				break;
			}
			case (Exception::Code::WrongListIndex) :
			{
				cout << exception.GetMessage() << endl;
				break;
			}
			case (Exception::Code::EmptyList) :
			{
				cout << exception.GetMessage() << endl;
				break;
			}
			}
			system("pause");
		}
	}
}