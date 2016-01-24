#include "exception.h"

Exception::Exception(Code _code, int _index)
{
	this->code = _code;
	this->index = _index;
}

Exception::Code Exception::GetCode() const
{
	return this->code;
}

const char *Exception::GetMessage() const
{
	char *message = new char[255];
	message = "undefinded error";
	switch (this -> code)
	{
	case (Code::EmptyList) :
	{
		message = "List has no items";
		break;
	}
	case (Code::NoListFounded) :
	{
		message = "Group has no items";
		break;
	}
	case (Code::WrongCommandIndex) :
	{
		message = "Wrong index of command";
		break;
	}
	case (Code::WrongListIndex) :
	{
		message = "Wrong index of list: ";
		break;
	}
	}
	return message;
}

Exception::~Exception()
{
}