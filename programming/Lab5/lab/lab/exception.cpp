#include "exception.h"



Exception::Exception()
{
}


Exception::Exception(Code, int index)
{
}

Code Exception::GetCode() const
{
	return Code();
}

const char * Exception::GetMessage() const
{
	return nullptr;
}

Exception::~Exception()
{
}
