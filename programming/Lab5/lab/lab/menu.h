#pragma once
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
		static string String();
	};
	static void PrintMenu();
};