#include "debug.h"

Debug::Debug()
{
	//int1 = Set<int>(5, 6, 9);
	/*int2 = new Set<int>(1, 5, 6, 9);*/
	//real1 = new Set<double>(0.5, 27.13);
	//real2 = new Set<double>(*real1);
	//char1 = new Set<char>(254, 'a', 'b');
	//char2 = new Set<char>();
	//user1 = new Set<Test>(Test("Programming"), Test("Math", 69));
	//user2 = new Set<Test>(Test(), Test("Assembly", 42));
}

void Debug::Print()
{
	//Menu::Output::ClrScr();
	//int1.Print();
	//int2.Print();
	//real1.Print();
	//real2.Print();
	//char1.Print();
	//char2.Print();
	//user1.Print();
	//user2.Print();
	//system("pause");
}

void Debug::HandleEvent(Event _event)
{
	//if (_event.IsValid())
	//{
	//	switch (_event.GetCommand())
	//	{
	//	case(Command::Add) :
	//	{
	//		Add(_event);
	//		break;
	//	}
	//	case(Command::Add1) :
	//	{
	//		Add1(_event);
	//		break;
	//	}
	//	case(Command::Add2) :
	//	{
	//		Add2(_event);
	//		break;
	//	}
	//	case(Command::Compare) :
	//	{
	//		Compare(_event);
	//		break;
	//	}
	//	case(Command::Multy) :
	//	{
	//		Multiply(_event);
	//		break;
	//	}
	//	case(Command::Print) :
	//	{
	//		Print(_event);
	//		break;
	//	}
	//	}
	//}
}

void Debug::Add1(Event _event)
{
	//Menu::Output::ClrScr();
	//switch (_event.GetType())
	//{
	//case (Types::Integer):
	//	{
	//		int1 + Menu::Input::Number("Enter integer for adding");
	//		break;
	//	}
	//case (Types::Real) :
	//{
	//	real1 + Menu::Input::NumberReal("Enter double for adding");
	//	break;
	//}
	//case (Types::Symbol) :
	//{
	//	real1 + Menu::Input::Symbol("Enter integer for adding");
	//	break;
	//}
	//case (Types::User) :
	//{
	//	user1 + 
	//		*(new Test(
	//			Menu::Input::String("Enter subject"), 
	//			Menu::Input::Number("Enter pounts"))
	//		);
	//	break;
	//}
	//}
}

void Debug::Add2(Event _event)
{
	//Menu::Output::ClrScr();
	//switch (_event.GetType())
	//{
	//case (Types::Integer) :
	//{
	//	int2 + Menu::Input::Number("Enter integer for adding");
	//	break;
	//}
	//case (Types::Real) :
	//{
	//	real2 + Menu::Input::NumberReal("Enter double for adding");
	//	break;
	//}
	//case (Types::Symbol) :
	//{
	//	real2 + Menu::Input::Symbol("Enter integer for adding");
	//	break;
	//}
	//case (Types::User) :
	//{
	//	user2 +
	//		*(new Test(
	//			Menu::Input::String("Enter subject"),
	//			Menu::Input::Number("Enter pounts"))
	//		);
	//	break;
	//}
	//}
}

void Debug::Add(Event _event)
{
	//Menu::Output::ClrScr();
	//switch (_event.GetType())
	//{
	//case (Types::Integer) :
	//{
	//	(int1 + int2)->Print();
	//}
	//case (Types::Real) :
	//{
	//	(real1 + real2)->Print();
	//}
	//case (Types::Symbol) :
	//{
	//	(char1 + char2)->Print();
	//}
	//case (Types::User) :
	//{
	//	(user1 + user2)->Print();
	//}
	//}
	//system("pause");
}

void Debug::Multiply(Event _event)
{
	//Menu::Output::ClrScr();
	//switch (_event.GetType())
	//{
	//case (Types::Integer):
	//{
	//	(int1 * int2)->Print();
	//}
	//case (Types::Real) :
	//{
	//	(real1 * real2)->Print();
	//}
	//case (Types::Symbol) :
	//{
	//	(char1 * char2)->Print();
	//}
	//case (Types::User) :
	//{
	//	(user1 * user2)->Print();
	//}
	//}
	//system("pause");
}

void Debug::Compare(Event _event)
{
	//Menu::Output::ClrScr();
	//cout << "Compare set1 <= set2: ";
	//switch (_event.GetType())
	//{
	//case (Types::Integer) :
	//{
	//	cout << (int1 <= int2);
	//}
	//case (Types::Real) :
	//{
	//	cout << (real1 <= real2);
	//}
	//case (Types::Symbol) :
	//{
	//	cout << (char1 <= char2);
	//}
	//case (Types::User) :
	//{
	//	cout << (user1 <= user2);
	//}
	//}
	//system("pause");
}

void Debug::Print(Event _event)
{
	//Menu::Output::ClrScr();
	//switch (_event.GetType())
	//{
	//case (Types::Integer) :
	//{
	//	int1.Print();
	//	int2.Print();
	//}
	//case (Types::Real) :
	//{
	//	real1.Print();
	//	real2.Print();
	//}
	//case (Types::Symbol) :
	//{
	//	char1.Print();
	//	char2.Print();
	//}
	//case (Types::User) :
	//{
	//	user1.Print();
	//	user2.Print();
	//}
	//}
	//system("pause");
}