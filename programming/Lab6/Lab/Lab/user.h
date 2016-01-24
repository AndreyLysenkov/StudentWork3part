#pragma once
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
	Test(char*, int);
	Test(char*);
	~Test();
	void GainPoints(int);
	const int GetPoints();
	const bool IsPassed();
	const double GetRating();
	void Set();
	bool operator ==(Test);
	friend std::ostream& operator<<(ostream&, Test&);
};