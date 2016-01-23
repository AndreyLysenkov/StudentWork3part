#pragma once
#include <iostream>

class Menu
{
public:
	class Input
	{
	public:
		static bool Boolean();
		static int Number();
		static string String();
		static char Char();
	};
	static void PrintMenu();
};