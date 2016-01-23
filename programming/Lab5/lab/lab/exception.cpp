#include "exception.h"


Exception::Exception(Code code, int index)
{
}

Exception::Code Exception::GetCode() const
{
	return Exception::Code::WrongCommandIndex;
}

const char *Exception::GetMessage() const
{
	return nullptr;
}

Exception::~Exception()
{
}