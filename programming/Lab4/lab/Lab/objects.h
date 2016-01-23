#pragma once
using namespace std;

class Trial
{
protected:
	string subject;
	string name;
public:
	Trial();
	Trial(Trial&);
	Trial(string, string);
	~Trial();
	void SetSubject(char*);
	void SetName(char*);
	char *GetSubject();
	char *GetName();
	virtual void Print();
	virtual void Enter();
};

class Test : public Trial
{
protected:
	int score;
	int maxScore;
	int minScore;
public:
	Test();
	Test(Test&);
	Test(string, string, int, int, int);
	~Test();
	void SetScore(int);
	int GetScore();
	int GetMaxScore();
	int GetMinScore();
	double GetRating();
	int GainScore(int);
	double GetMinRating();
	virtual void Print();
	virtual void Enter();
};

class Exam : public Trial
{
protected:
	int mark;
	bool isPassed;
public:
	Exam();
	Exam(Exam&);
	Exam(string, string);
	~Exam();
	int GetMark();
	bool SetMark(int);
	bool IsPassed();
	virtual void Print();
	virtual void Enter();
};

class FinalExam : public Exam
{
private:
	bool isAccessed;
	int finalMark;
public:
	FinalExam();
	FinalExam(FinalExam&);
	FinalExam(string, string);
	~FinalExam();
	bool IsAccessed();
	void GainAccess();
	void SetFinalMark(int, int[], int);
	int GetFinalMark();
	virtual void Print();
	virtual void Enter();
};