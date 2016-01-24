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
		CommandMenu *holder = new CommandMenu(_event);
		switch (_event.GetCommand())
		{
		case(Command::Add) :
		{
			holder->Add();
			break;
		}
		case(Command::Add1) :
		{
			holder->Add1();
			break;
		}
		case(Command::Add2) :
		{
			holder->Add2();
			break;
		}
		case(Command::Compare) :
		{
			holder->Compare();
			break;
		}
		case(Command::Multy) :
		{
			holder->Multiply();
			break;
		}
		case(Command::Print) :
		{
			holder->Print();
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
	}
}

void Debug::Add2(Event _event)
{
}

void Debug::Add(Event _event)
{
}

void Debug::Multiply(Event _event)
{
}

void Debug::Compare(Event _event)
{
}

void Debug::Print(Event _event)
{
}

//
//void Demo::AddFirst(Event ev)
//{
//	system("cls");
//	switch (ev.GetType())
//	{
//	case Event::T_int:
//	{
//		firstI.Print();
//		int I;
//		cin >> i;
//		firstI + i;
//		break;
//	}
//	case Event::T_char:
//	{
//		firstC.Print();
//		char ch;
//		cin >> ch;
//		firstC + ch;
//		break;
//	}
//	case Event::T_double:
//	{
//		firstC.Print();
//		double db;
//		cin >> db;
//		firstD + db;
//		break;
//	}
//	case Event::T_State:
//	{
//		firstS.Print();
//		State state;
//		state.SetAll();
//		firstS + state;
//		break;
//	}
//	}
//}
//
//
//void Demo::GetSize(Event ev)
//{
//	system("cls");
//	switch (ev.GetType())
//	{
//	case Event::T_int:
//	{
//		firstI.Print();
//		cout << firstI;
//		secondI.Print();
//		cout << secondI;
//		break;
//	}
//	case Event::T_char:
//	{
//		firstC.Print();
//		cout << firstC;
//		secondC.Print();
//		cout << secondC;
//		break;
//	}
//	case Event::T_double:
//	{
//		firstD.Print();
//		cout << firstD;
//		secondD.Print();
//		cout << secondD;
//		break;
//	}
//	case Event::T_State:
//	{
//		firstS.Print();
//		cout << firstS;
//		secondS.Print();
//		cout << secondS;
//		break;
//	}
//	}
//	system("pause");
//}


//
//void Demo::Intersection(Event ev)
//{
//	system("cls");
//	switch (ev.GetType())
//	{
//	case Event::T_int:
//	{
//		firstI.Print();
//		secondI.Print();
//		cout << " Intersection resut:\n";
//		(firstI * secondI)->Print();
//		break;
//	}
//	case Event::T_char:
//	{
//		firstC.Print();
//		secondC.Print();
//		cout << " Intersection resut:\n";
//		(firstC * secondC)->Print();
//		break;
//	}
//	case Event::T_double:
//	{
//		firstD.Print();
//		secondD.Print();
//		cout << " Intersection resut:\n";
//		(firstD * secondD)->Print();
//		break;
//	}
//	case Event::T_State:
//	{
//		firstS.Print();
//		secondS.Print();
//		cout << " Intersection resut:\n";
//		(firstS * secondS)->Print();
//		break;
//	}
//	}
//	system("pause");
//}