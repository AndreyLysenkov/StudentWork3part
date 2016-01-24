#include "menu.h"

int Menu::Input::Number(char *message)
{
	int number = 0;
	do
	{
		cout << " > " << message << ":";
		cout << " > ";
		cin >> number;
	} while (!(cin.fail()));
	return number;
}

char *Menu::Input::String(char *message)
{
	char *str = new char[255];
	cout << " > " << message << ":";
	cout << " > ";
	cin.get();
	cin.getline(str, 255);
	return str;
}

void Menu::Output::MenuItem(char* actionName, int actionIndex)
{
	cout << endl << actionIndex << " > " << actionName;
}

int Menu::Output::Menu()
{
	cout << " --- Action ---";
	MenuItem("Add to 1st set", Command::Add1);
	MenuItem("Add to 2nd set", Command::Add2);
	MenuItem("Add set1 to set2", Command::Add);
	MenuItem("Multiply set1 and set2", Command::Multy);
	MenuItem("Compare set1 and set2", Command::Compare);
	MenuItem("Print set", Command::Print);
	MenuItem("Exit", Command::Exit);
	cout << endl;
	return Menu::Input::Number();
}

void Menu::Output::ClrScr()
{
	system("cls");
}

void Menu::Output::RunMenu()
{
	//Group group;
	//Event _event;
	//int menuIndex = Command::Exit;
	//do
	//{
	//	Menu::Output::ClrScr();
	//	menuIndex = Menu::Output::Menu();
	//	_event.Create(menuIndex);
	//	group.HandleEvent(_event);
	//} while (menuIndex != Command::Exit);
}


//
//void Menu::PrintMenu()
//{
//	cout << "\n " << Event::Cmd_AddFirst << " - Add to first";
//	cout << "\n " << Event::Cmd_AddSecond << " - Add to second";
//	cout << "\n " << Event::Cmd_Intersection << " - Get intersection of sets";
//	cout << "\n " << Event::Cmd_Print << " - Print all sets";
//	cout << "\n " << Event::Cmd_GetSize << " - Get size of set";
//	cout << "\n " << Event::Cmd_Exit << " - Exit\n\n> ";
//}
//
//void Menu::PrintTypeSelection()
//{
//	cout << "\n " << Event::T_int << " - int";
//	cout << "\n " << Event::T_char << " - char";
//	cout << "\n " << Event::T_double << " - double";
//	cout << "\n " << Event::T_State << " - State\n\n> ";
//}
//
//int Menu::SelectType()
//{
//	int selector;
//	do
//	{
//		system("cls");
//		PrintTypeSelection();
//		selector = ReadNumber();
//	} while (selector <= Event::T_Back || selector > Event::T_State);
//	return selector;
//}
//
//void Menu::Execute()
//{
//	Demo demo;
//	Event ev;
//	int selector;
//	do
//	{
//		system("cls");
//		PrintMenu();
//		selector = ReadNumber();
//		int type = Event::T_Back;
//		if (selector != Event::Cmd_Exit && selector != Event::Cmd_Print)
//		{
//			type = SelectType();
//		}
//		ev.CreateEvent(selector, type);
//		demo.HandleEvent(ev);
//	} while (ev.GetCommand() != Event::Cmd_Exit);
//}
//void Demo::HandleEvent(Event ev)
//{
//	if (ev.IsRelevant() && ev.GetCommand() != Event::Cmd_Exit)
//	{
//		switch (ev.GetCommand())
//		{
//		case Event::Cmd_AddFirst:
//		{
//			AddFirst(ev);
//			break;
//		}
//		case Event::Cmd_AddSecond:
//		{
//			AddSecond(ev);
//			break;
//		}
//		case Event::Cmd_Print:
//		{
//			Print();
//			break;
//		}
//		case Event::Cmd_GetSize:
//		{
//			GetSize(ev);
//			break;
//		}
//		case Event::Cmd_Intersection:
//		{
//			Intersection(ev);
//			break;
//		}
//		}
//	}
//}

