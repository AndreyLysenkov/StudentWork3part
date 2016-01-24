#include "debug.h"

Debug::Debug()
{
}

void Debug::Print()
{
	Menu::Output::ClrScr();
	int1.Print();
	int2.Print();
	real1.Print();
	real2.Print();
	char1.Print();
	char2.Print();
	user1.Print();
	user2.Print();
	system("pause");
}

void Debug::HandleEvent(Event _event)
{
	if (_event.IsValid())
	{
		switch (_event.GetCommand())
		{
		case(Command::Add) :
		{
			Add(_event);
			break;
		}
		case(Command::Add1) :
		{
			Add1(_event);
			break;
		}
		case(Command::Add2) :
		{
			Add2(_event);
			break;
		}
		case(Command::Compare) :
		{
			Compare(_event);
			break;
		}
		case(Command::Multy) :
		{
			Multiply(_event);
			break;
		}
		case(Command::Print) :
		{
			Print(_event);
			break;
		}
		}
	}
}

void Debug::Add1(Event _event)
{
	Menu::Output::ClrScr();
	switch (_event.GetType())
	{
	case (Types::Integer):
		{
			int1 + Menu::Input::Number("Enter integer for adding");
			break;
		}
	case (Types::Real) :
	{
		real1 + Menu::Input::NumberReal("Enter double for adding");
		break;
	}
	case (Types::Symbol) :
	{
		real1 + Menu::Input::Symbol("Enter integer for adding");
		break;
	}
	case (Types::User) :
	{
		user1 + 
			*(new Test(
				Menu::Input::String("Enter subject"), 
				Menu::Input::Number("Enter pounts"))
			);
		break;
	}
	}
}

void Debug::Add2(Event _event)
{
	Menu::Output::ClrScr();
	switch (_event.GetType())
	{
	case (Types::Integer) :
	{
		int2 + Menu::Input::Number("Enter integer for adding");
		break;
	}
	case (Types::Real) :
	{
		real2 + Menu::Input::NumberReal("Enter double for adding");
		break;
	}
	case (Types::Symbol) :
	{
		real2 + Menu::Input::Symbol("Enter integer for adding");
		break;
	}
	case (Types::User) :
	{
		user2 +
			*(new Test(
				Menu::Input::String("Enter subject"),
				Menu::Input::Number("Enter pounts"))
			);
		break;
	}
	}
}

void Debug::Add(Event _event)
{
	Menu::Output::ClrScr();
	switch (_event.GetType())
	{
	case (Types::Integer) :
	{
		(int1 + int2)->Print();
	}
	case (Types::Real) :
	{
		(real1 + real2)->Print();
	}
	case (Types::Symbol) :
	{
		(char1 + char2)->Print();
	}
	case (Types::User) :
	{
		(user1 + user2)->Print();
	}
	}
	system("pause");
}

void Debug::Multiply(Event _event)
{
	Menu::Output::ClrScr();
	switch (_event.GetType())
	{
	case (Types::Integer):
	{
		(int1 * int2)->Print();
	}
	case (Types::Real) :
	{
		(real1 * real2)->Print();
	}
	case (Types::Symbol) :
	{
		(char1 * char2)->Print();
	}
	case (Types::User) :
	{
		(user1 * user2)->Print();
	}
	}
	system("pause");
}

void Debug::Compare(Event _event)
{
}

void Debug::Print(Event _event)
{
}



