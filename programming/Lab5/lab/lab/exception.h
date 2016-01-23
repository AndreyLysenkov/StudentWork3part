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
		WrongTemplate,
		WrongUFO,
		Wron404
	};
	Exception(Code, int index = -1);
	Code GetCode() const;
	const string GetMessage() const;
	~Exception();
private:
	Code code;
	string message;
	int index;
};