#include "menu.h"

bool Menu::Input::Boolean()
{
	return false;
}

int Menu::Input::Number()
{
	int number = 0;
	do
	{
		cout << " > ";
		cin >> number;
	} while (!(cin.fail()));
	return number;
}

char *Menu::Input::String()
{
	return NULL;
}

char Menu::Input::Char()
{
	return 0;
}

void Menu::Output::MenuItem(char* actionName, int actionIndex)
{
	cout << endl << actionIndex << " > " << actionName;
}

int Menu::Output::Menu()
{
	cout << " --- Action ---";
	MenuItem("Create list", Command::Create);
	MenuItem("Add char to list", Command::Add);
	MenuItem("Remove char from list", Command::Remove);
	MenuItem("Copy list", Command::Copy);
	MenuItem("Delete list", Command::Delete);
	MenuItem("Compare lists", Command::Compare);
	MenuItem("Print list", Command::Print);
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
	Group group;
	Event _event;
	int menuIndex = Command::Exit;
	do
	{
		Menu::Output::ClrScr();
		menuIndex = Menu::Output::Menu();
		_event.Create(menuIndex);
		group.HandleEvent(_event);
	} while (menuIndex != Command::Exit);
}
//int Menu::ReadNumber()
//{
//	int x;
//	cin >> x;
//	while (cin.fail())
//	{
//		char fail;
//		cin.clear();
//		cin >> fail;
//		cin >> x;
//	}
//	return x;
//}

