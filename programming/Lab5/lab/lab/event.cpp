#include "event.h"
using namespace std;

Event::Event()
{
	this->command = Command::Undefinded;
}

Event::~Event()
{
}

void Event::Clear()
{
	this->command = Command::Undefinded;
}

bool Event::IsValid()
{
	return (this->command == Command::Undefinded);
}

int Event::GetCommand()
{
	return this->command;
}

void Event::SetCommand(int _command)
{
	if (CheckCommand(_command))
	{
		this->command = _command;
	}
	else
	{
		throw Exception(Exception::Code::WrongCommandIndex);
	}
}

bool Event::CheckCommand(int _command)
{
	return (_command >= -1) && (_command <= 6);
}

void Event::Create(int _command)
{
	try
	{
		this->SetCommand(_command);
	}
	catch (Exception myException)
	{
		cout << myException.GetMessage() << endl;
		SetCommand(Command::Print);
		system("pause");
	}
}