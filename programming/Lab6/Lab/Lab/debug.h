#pragma once
#include "set.h"
#include "user.h"
#include "event.h"

class Debug
{
	Set<int> int1;
	Set<int> int2;
	Set<char> char1;
	Set<char> char2;
	Set<double> real1;
	Set<double> real2;
	Set<Test> user1;
	Set<Test> user2;
	void Print();
public:
	Debug();
	void HandleEvent(Event);
};

//	void AddFirst(Event);
//	void AddSecond(Event);
//	void Intersection(Event);
//	void Print();
//	void GetSize(Event);
//};
