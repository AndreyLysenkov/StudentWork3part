#pragma once
#include "user.h"
#include "event.h"
#include "menu.h"
#include <iostream>
#include "set.h"
using namespace std;

class Debug
{
private:
	Set<int> *int1;
	Set<int> *int2;
	Set<char> *char1;
	Set<char> *char2;
	Set<double> *real1;
	Set<double> *real2;
	Set<Test> *user1;
	Set<Test> *user2;

	void Add1(Event);
	void Add2(Event);
	void Add(Event);
	void Multiply(Event);
	void Compare(Event);
	void Print(Event);
public:
	Debug();
	void Print();
	void HandleEvent(Event);
};