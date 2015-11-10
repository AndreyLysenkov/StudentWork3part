#pragma once
#include <string>
using namespace std;

class Trial
{
protected:
	string subject;
public:
	Trial();
	Trial(Trial&);
	Trial(string);
	~Trial();
	string GetSubject();

};

class Test : public Trial
{
protected:
	int score;
	static int maxScore;
public:
	Test();
	Test(Test&);
	Test(string, int);
	~Test();

};

class Exam : public Trial
{

};

class FinalExam : public Exam
{

};