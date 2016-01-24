#pragma once
#include <iostream>
using namespace std;

class Exception
{
public:
	enum Code
	{
		NoError,
		EmptyList,
		WrongListIndex,
		WrongCommandIndex,
		NoListFounded
	};
	Exception(Code, int index = -1);
	Code GetCode() const;
	const char *GetMessage() const;
	~Exception();
private:
	Code code;
	int index;
};