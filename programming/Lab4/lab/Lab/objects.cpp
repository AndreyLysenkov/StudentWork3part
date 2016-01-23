#define _CRT_SECURE_NO_WARNINGS
#include "objects.h"
#include <iostream>
#include <string>
using namespace std;

int MAX_CHAR_SIZE = 100;

Trial::Trial()
{
	this->name = "";
	this->subject = "";
}

Trial::Trial(string _name, string _subject)
{
	this->name = _name;
	this->subject = _subject;
}

Trial::Trial(Trial &obj)
{
	this->name = obj.GetName();
	this->subject = obj.GetSubject();
}

Trial::~Trial()
{

}

void Trial::SetSubject(string _subject)
{
	this->subject = _subject;
}

void Trial::SetName(string _name)
{
	this->name = _name;
}

string Trial::GetSubject()
{
	return this->subject;
}

string Trial::GetName()
{
	return this->name;
}

void Trial::Print()
{
	cout << endl << "Object #" << this << endl;
	cout << " Subject : " << this->GetSubject() << endl;
	cout << " Name : " << this->GetName() << endl;
}

void Trial::Enter()
{
	string name;
	string subject;
	cout << "Enter Trial: " << endl;
	cout << " Subject > ";
	cin >> subject;
	cout << " Name > ";
	cin >> name;
	SetName(name);
	SetSubject(subject);
}


Test::Test() : Trial()
{
	this->score = 0;
	this->maxScore = 0;
	this->minScore = 0;
}

Test::Test(string _name, string _subject,
	int _score = 0, int _maxScore = 100, int _minScore = 0)
	: Trial(_name, _subject)
{
	this->score = _score;
	this->maxScore = _maxScore;
	this->minScore = _minScore;
}

Test::Test(Test &obj)
	: Trial(obj.GetName(), obj.GetSubject())
{
	this->maxScore = obj.GetMaxScore();
	this->score = obj.GetScore();
	this->minScore = obj.GetMinScore();
}

Test::~Test()
{
	
}

void Test::SetScore(int _score)
{
	this->score = _score;
}

int Test::GetScore()
{
	return this->score;
}

int Test::GetMaxScore()
{
	return this->maxScore;
}

int Test::GetMinScore()
{
	return this->minScore;
}

double Test::GetRating()
{
	return score / (double)maxScore;
}

int Test::GainScore(int add)
{
	this->score += add;
	return this->score;
}

double Test::GetMinRating()
{
	return minScore / (double)maxScore;
}

void Test::Print()
{
	((Trial)*this).Print();
	cout << " Mark : " << this->GetScore() << "/" << this->GetMaxScore()
		<< "(min : " << this->GetMinScore() << ")" << endl;
}

void Test::Enter()
{
	((Trial)(*this)).Enter();
	int score;
	int minScore;
	int maxScore;
	cout << "Enter Trial: " << endl;
	cout << " Score > ";
	cin >> score;
	SetScore(score);
	cout << " MaxScore > ";
	cin >> maxScore;
	SetScore(maxScore);
	cout << " MinScore > ";
	cin >> minScore;
	SetScore(minScore);
}


Exam::Exam()
	: Trial()
{
	this->isPassed = false;
	this->mark = 0;
}

Exam::Exam(string _name, string _subject)
	: Trial(_name, _subject)
{
	this->mark = 0;
	this->isPassed = false;
}

Exam::Exam(Exam &obj)
	: Trial(obj.GetName(), obj.GetSubject())
{
	this->isPassed = obj.isPassed;
	this->mark = obj.mark;
}

Exam::~Exam()
{
	
}

int Exam::GetMark()
{
	return this->mark;
}

bool Exam::SetMark(int _mark)
{
	if (this->IsPassed())
	{
		return false;
	}
	this->mark = _mark;
	return true;
}

bool Exam::IsPassed()
{
	return this->isPassed;
}

void Exam::Print()
{
	((Trial)*this).Print();
	cout << " Passed : " << this->IsPassed() << endl;
	cout << " Mark : " << this->GetMark() << endl;
}

void Exam::Enter()
{
	((Trial)(*this)).Enter();
	int mark;
	cout << " Mark > ";
	cin >> mark;
	SetMark(mark);
}


FinalExam::FinalExam()
	: Exam()
{
	this->isAccessed = false;
	this->finalMark = 0;
}

FinalExam::FinalExam(string _name, string _subject)
	: Exam(_name, _subject)
{
	this->isAccessed = false;
	this->finalMark = 0;
}

FinalExam::FinalExam(FinalExam &obj)
	: Exam(obj.GetName(), obj.GetSubject())
{
	this->isAccessed = obj.IsAccessed();
	this->finalMark = obj.GetFinalMark();
}

FinalExam::~FinalExam()
{
	
}

bool FinalExam::IsAccessed()
{
	return this->isAccessed;
}

void FinalExam::GainAccess()
{
	this->isAccessed = true;
}

void FinalExam::SetFinalMark(int _finalMark, int prevMark[], int marksCount)
{
	if (marksCount == 0)
	{
		this->finalMark = _finalMark;
	}
	else
	{
		double average = 0;
		for (int i = 0; i < marksCount; i++)
		{
			average += prevMark[i];
		}
		average = (average / marksCount + this->mark) / 2;
		this->finalMark = (int)average;
	}
}

int FinalExam::GetFinalMark()
{
	return this->finalMark;
}

void FinalExam::Print()
{
	((Exam)*this).Print();
	cout << " Access: " << this->IsAccessed() << endl;
	cout << " FinalMark: " << this->GetFinalMark() << endl;
}

void FinalExam::Enter()
{
	((Exam)(*this)).Enter();
	cout << " FinalMark > ";
	int finalMark;
	cin >> finalMark;
	SetFinalMark(finalMark, NULL, 0);
	cout << " Access > ";
	bool Access;
	cin >> Access;
	if (Access)
	{
		this -> GainAccess();
	}
}