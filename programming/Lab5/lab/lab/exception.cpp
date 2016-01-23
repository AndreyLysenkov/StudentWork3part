#include "exception.h"


Exception::Exception(Code code, int index)
{
}

Exception::Code Exception::GetCode() const
{
	return Exception::Code::Wron404;
}

const string Exception::GetMessage() const
{
	return nullptr;
}

Exception::~Exception()
{
}