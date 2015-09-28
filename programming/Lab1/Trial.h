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
private:
	int score;
	int maxScore;
public:
	Test();
	Test(Test&);
	Test(string, int);
	~Test();
	double GetRightness();
	void GainScore(int);
};

class Exam : public Trial
{
protected:
	int mark;
	bool isPassed;
public:
	Exam();
	Exam(Exam&);
	Exam(string);
	~Exam();
	int GetMark();
	void SetMark(int);
	void Passed();
	bool IsPassed();
};

class FinalExam : public Exam
{
private:
	bool isAccessed;
	int finalMark;
public:
	FinalExam();
	FinalExam(FinalExam&);
	FinalExam(string);
	~FinalExam();
	void IsAccessed();
	void GainAccessed();
	void SetFinalMark(int);
};