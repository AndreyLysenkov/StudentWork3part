#pragma once
#include <iostream>
using namespace std;

class Test
{
private:
	int maxPoints;
	int points;
public:
	Test();
	Test(int, int);
	Test(const Test&);
	int GetPoints() const;
	int GetMaxPoints() const;
	void GainPoints(int);
	double GetRating() const;
	void Set(int, int);
	bool operator <(Test);
	bool operator >(Test);
	bool operator ==(Test);
	bool operator !=(Test);
	Test& operator = (const Test&);
	friend ostream& operator << (ostream&, Test&);
	friend istream& operator >> (istream&, Test&);
};