#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"
#include <iostream>
using namespace std;

class Test
{
private:
	char *subject;
	int point;
	static int minPoint;
	static int maxPoint;
public:
	Test();
	Test(Test&);
	Test(char*, int = 0);
	~Test();
	void GainPoints(int);
	const int GetPoints();
	const char *GetSubject();
	const bool IsPassed();
	const double GetRating();
	void Set();
	bool operator ==(Test);
	friend std::ostream& operator<<(ostream&, Test&);
};