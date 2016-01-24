#include "event.h"
using namespace std;

int Event::COMMAND_SHIFT = 8;

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
	return (this->command) / Event::COMMAND_SHIFT;
}

int Event::GetType()
{
	return this->command % Event::COMMAND_SHIFT;
}

void Event::SetCommand(int _command)
{
	if (CheckCommand(_command / Event::COMMAND_SHIFT) 
		&& Menu::Output::CheckTypeIndex(_command % Event::COMMAND_SHIFT))
	{
		this->command = _command;
	}
	else
	{
		//throw Exception(Exception::Code::WrongCommandIndex);
	}
}

bool Event::CheckCommand(int _command)
{
	return (_command >= 0) && (_command <= 6);
}

void Event::Create(int _command, int _type)
{
	//try
	//{
		this->SetCommand(_command * Event::COMMAND_SHIFT + _type);
	//}
	//catch (Exception myException)
	//{
	//	cout << myException.GetMessage() << endl;
	//	SetCommand(Command::Print);
	//	system("pause");
	//}
}