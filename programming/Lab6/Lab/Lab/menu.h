#pragma once
#include "event.h"
#include <iostream>
using namespace std;

class Menu
{
public:
	class Input
	{
	public:
		static int Number(char* = "Enter number");
		static char *String(char* = "Enter string");
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