#include "Trial.h"
#include <string>
#include <iostream>
using namespace std;

int Test::maxScore = 100;

Trial::Trial()
{
	this -> subject = "undefinded";
}

Trial::Trial(string _subject)
{
	this -> subject = _subject;
}

Trial::Trial(Trial &obj)
{
	this -> subject = obj.subject;
}

Trial::~Trial()
{
	cout << "Deleting trial: " << this << endl;
}

string Trial::GetSubject()
{
	return this -> subject;
}

void Test::GainScore(int _score)
{
	this -> score = _score;
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

void Test::GainScore(int _score)
{
	this -> score = _score;
}

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