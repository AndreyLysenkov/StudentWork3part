#pragma once
#include "event.h"
#include "group.h"
#include <iostream>
using namespace std;

class Menu
{
public:
	class Input
	{
	public:
		static bool Boolean();
		static int Number();
		static char *String();
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