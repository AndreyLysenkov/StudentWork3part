#include "list.h"
#include "exception.h"

List::List()
{
	this->last = NULL;
}

List & List::operator=(List &obj)
{
	this->last = NULL;
	if (obj.GetLast() != NULL) {
		Element *temp = NULL;
		Element *current = obj.GetLast();
		do {
			Element *newTemp = new Element();
			newTemp->next = temp;
			newTemp->symbol = current->symbol;
			temp = newTemp;
			current = current->next;
		} while (current != NULL);
		while (temp != NULL)
		{
			Element *prevLast = this->last;
			this->last = new Element();
			this->last->symbol = temp->symbol;
			this->last->next = prevLast;
			temp = temp->next;
		}
	}
	return *this;
}

void List::operator+(char ch)
{
	Element *temp = new Element();
	temp->symbol = ch;
	temp->next = this->last;
	this->last = temp;
}

void List::operator--()
{
	if (this->last != NULL)
	{
		last = last->next;
	}
	else
	{
		throw Exception(Exception::Code::EmptyList);
	}
}

bool List::operator!=(List list)
{
	bool result = true;
	Element *list1 = this->GetLast();
	Element *list2 = list.GetLast();
	while (result && (list1 != NULL) && (list2 != NULL))
	{
		result = (list1->symbol == list2->symbol);
		list1 = list1->next;
		list2 = list2->next;
	};
	if (result)
	{
		result = (list1 != NULL) && (list2 != NULL);
	}
	return !result;
}

void List::Print()
{
	cout << this;
}

void List::Input()
{
	char* temp = new char[255];
	cin.get();
	cin.getline(temp, 255);
	for (int i = 0; i <= strlen(temp); i++)
	{
		*this + temp[i];
	}
}

Element * List::GetLast()
{
	return this->last;
}

List::~List()
{
}

ostream & operator<<(ostream &stream, List &list)
{
	Element *temp = list.last;
	if (temp == NULL)
		stream << "Empty List";
	while (temp != NULL)
	{
		stream << " > " << temp->symbol << endl;
		temp = temp->next;
	}
	return stream;
}

istream & operator<<(istream &stream, List &list)
{
	char temp;
	stream >> temp;
	list + temp;
	return stream;
}