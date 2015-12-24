#include "Trial.h"
#include <string>
#include <iostream>
using namespace std;

int MAX_CHAR_SIZE = 100;

int Test::maxScore = 100;


/* Trial */

Trial::Trial()
{
	this->name = "";
	this->subject = "";
	this->score = 0;
}

Trial::Trial(char *_name, char *_subject, int _score)
{
	this->name = new char[MAX_CHAR_SIZE];
	strcpy(name, _name);
	this->subject = new char[MAX_CHAR_SIZE];
	strcpy(subject, _subject);
	this->score = _score;
}

Trial::Trial(Trial &obj)
{
	this->name = new char[MAX_CHAR_SIZE];
	strcpy(name, obj.GetName());
	this->subject = new char[MAX_CHAR_SIZE];
	strcpy(subject, obj.GetSubject());
	this->score = obj.GetScore();
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

void Trial::SetScore(int _score)
{
	this->score = _score;
}

void Trial::SetName(char *_name)
{
	this->name = new char[MAX_CHAR_SIZE];
	strcpy(name, _name);
}

char * Trial::GetSubject()
{
	return this->subject;
}

char * Trial::GetName()
{
	return this->name;
}

int Trial::GetScore()
{
	return this->score;
}

int Trial::GainScore(int add)
{
	this->score += add;
	return this->score;
}




Test::Test() : Trial()
{
	this -> score = 0;
}

Test::Test(string subject, int maxScore) : Trial(subject)
{
	this -> maxScore = maxScore;
	this -> score = 0;
}

Test::Test(Test &obj) : Trial((Trial)obj)
{
	this -> maxScore = obj.maxScore;
	this -> score = obj.score;
}

Test::~Test()
{
	cout << "Deleting your test: " << this << endl;
}

double Test::GetRating()
{
	return score / (double)maxScore;
}

//void Test::GainScore(int _score)
//{
//	this -> score = _score;
//}

Exam::Exam() : Trial()
{
	this -> isPassed = false;
	this -> mark = 0;
}

Exam::Exam(string subject) : Trial(subject)
{
	this -> mark = 0;
	this -> isPassed = false;
}

Exam::Exam(Exam &obj) : Trial((Exam)obj)
{
	this -> isPassed = obj.isPassed;
	this -> mark = obj.mark;
}

Exam::~Exam()
{
	cout << "Delete object " << this << endl;
}

int Exam::GetMark()
{
	return this -> mark;
}

void Exam::SetMark(int _mark)
{
	this -> mark = mark;
}

void Exam::Passed()
{
	this -> isPassed = true;
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

FinalExam::FinalExam(string subject) : Exam(subject)
{
	this -> isAccessed = false;
	this -> finalMark = 0;
}

FinalExam::FinalExam(FinalExam &obj) : Exam((Exam)obj)
{
	this -> isAccessed = obj.isAccessed;
	this -> finalMark = obj.finalMark;
}

FinalExam::~FinalExam()
{
	cout << "Deleteing final exam: " << this << endl;
}

bool FinalExam::IsAccessed()
{
	return this -> isAccessed;
}

void FinalExam::GainAccessed()
{
	this -> isAccessed = true;
}

void FinalExam::SetFinalMark(int _finalMark)
{
	this -> finalMark = _finalMark;
}