#pragma once
#include "event.h"
#include <iostream>
using namespace std;

enum Types
{
	Integer = 1,
	Real = 2,
	Symbol = 3,
	User = 4
};

class Menu
{
public:
	class Input
	{
	public:
		static double NumberReal(char* = "Enter double");
		static int Number(char* = "Enter integer");
		static char *String(char* = "Enter string");
		static char Symbol(char* = "Enter char");
	};
	class Output
	{
	private:
		static void MenuItem(char*, int);
	public:
		static bool CheckTypeIndex(int);
		static int Menu();
		static int TypeChoose();
		static void ClrScr();
	};
};