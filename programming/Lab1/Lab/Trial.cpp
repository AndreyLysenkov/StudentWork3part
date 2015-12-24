#include "Trial.h"
#include <string>
#include <iostream>
using namespace std;

int MAX_CHAR_SIZE = 100;

/* Trial */

Trial::Trial()
{
	this->name = "";
	this->subject = "";
}

Trial::Trial(char *_name, char *_subject)
{
	this->name = new char[MAX_CHAR_SIZE];
	strcpy(name, _name);
	this->subject = new char[MAX_CHAR_SIZE];
	strcpy(subject, _subject);
}

Trial::Trial(Trial &obj)
{
	this->name = new char[MAX_CHAR_SIZE];
	strcpy(name, obj.GetName());
	this->subject = new char[MAX_CHAR_SIZE];
	strcpy(subject, obj.GetSubject());
}

Trial::~Trial()
{
	cout << "Deleting trial: " << this << endl;
	delete name;
	delete subject;
}

void Trial::SetSubject(char *_subject)
{
	this->subject = new char[MAX_CHAR_SIZE];
	strcpy(subject, _subject);
}

void Trial::SetName(char *_name)
{
	this->name = new char[MAX_CHAR_SIZE];
	strcpy(name, _name);
}

char *Trial::GetSubject()
{
	return this->subject;
}

char *Trial::GetName()
{
	return this->name;
}


Test::Test() : Trial()
{
	this -> score = 0;
}

Test::Test(char *_name, char *_subject,
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
	cout << "Deleting your Test: " << this << endl;
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


Exam::Exam() : Trial()
{
	this -> isPassed = false;
	this -> mark = 0;
}

Exam::Exam(char *_name, char *_subject)
	: Trial(_name, _subject)
{
	this -> mark = 0;
	this -> isPassed = false;
}

Exam::Exam(Exam &obj)
	: Trial(obj.GetName(), obj.GetSubject())
{
	this -> isPassed = obj.isPassed;
	this -> mark = obj.mark;
}

Exam::Exam(char *_name, char *_subject)
	: Trial(_name, _subject)
{

}

Exam::~Exam()
{
	cout << "Delete object " << this << endl;
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
	this -> mark = _mark;
	return true;
}

bool Exam::IsPassed()
{
	return this -> isPassed;
}


FinalExam::FinalExam() : Exam()
{
	this -> isAccessed = false;
	this -> finalMark = 0;
}

FinalExam::FinalExam(char *_name, char *_subject)
	: Exam(_name, _subject)
{
	this -> isAccessed = false;
	this -> finalMark = 0;
}

FinalExam::FinalExam(FinalExam &obj)
	: Exam(obj.GetName(), obj.GetSubject())
{
	this -> isAccessed = obj.IsAccessed();
	this -> finalMark = obj.GetFinalMark();
}

FinalExam::~FinalExam()
{
	cout << "Deleteing final exam: " << this << endl;
}

bool FinalExam::IsAccessed()
{
	return this -> isAccessed;
}

void FinalExam::GainAccess()
{
	this->isAccessed = true;
}

void FinalExam::SetFinalMark(int _finalMark, int prevMark[], int marksCount)
{
	double average = 0;
	for (int i = 0; i < marksCount; i++)
	{
		average += prevMark[i];
	}
	average = (average / marksCount + this->finalMark) / 2;
	this->finalMark = (int)average;
}

int FinalExam::GetFinalMark()
{
	return this->finalMark;
}