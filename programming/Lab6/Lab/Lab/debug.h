#pragma once
#include "set.h"
#include "user.h"
#include "event.h"
#include "menu.h"
#include <iostream>
using namespace std;

class Debug
{
private:
	Set<int> int1;
	Set<int> int2;
	Set<char> char1;
	Set<char> char2;
	Set<double> real1;
	Set<double> real2;
	Set<Test> user1;
	Set<Test> user2;

public:
	void HandleEvent(Event);
};

//class Debug
//{
//	void Print();
//public:
//	Debug();
//	void HandleEvent(Event);
//};
//
////	void AddFirst(Event);
////	void AddSecond(Event);
////	void Intersection(Event);
////	void Print();
////	void GetSize(Event);
////};
