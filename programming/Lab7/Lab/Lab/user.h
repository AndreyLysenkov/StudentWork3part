#pragma once
#include <iostream>
using namespace std;

class Test
{
private:
	char *subject;
	int points;
public:
	Test();
	Test(char*, int);
	Test(const Test&);
	char *GetSubject();
	int GetPoints();
	int GainPoints(int);
	bool operator <(Test);
	bool operator >(Test);
	bool operator ==(Test);
	bool operator !=(Test);
	Test& operator = (const Test&);
	friend ostream& operator << (ostream&, Test&);
	friend istream& operator >> (istream&, Test&);
};