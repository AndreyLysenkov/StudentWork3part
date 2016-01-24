#pragma once
#include <iostream>
using namespace std;

enum Command
{
	Create = 1,
	Add = 2,
	Remove = 3,
	Copy = 4,
	Delete = 5,
	Compare = 6,
	Print = 7,
	Exit = 0,
	Undefinded = 0
};

class Menu
{
public:
	class Input
	{
	public:
		static int Number();
		static char Char();
	};
	class Output
	{
	private:
		static void MenuItem(char*, int);
		static int Menu();
	public:
		static void ClrScr();
		static void RunMenu();
	};
};