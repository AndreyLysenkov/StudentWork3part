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
	void GainScore(int);
};

class Test : public Trial
{
private:
	int score;
public:
	Test();
	Test(Test&);
	Test(string);
	~Test();
	int GetScore();
	void GainScore();
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
	void SetMark();
	void Passed();
	bool IsPassed();
};

class FinalExam : public Exam
{
private:
	Exam exams[10];
	int exams_count;
	bool isPassed;
public:
	FinalExam();
	FinalExam(FinalExam&);
	FinalExam(string);
	~FinalExam();
	void SetExams(Exam exam[], int exams_count);
	Exam GetExam(int position);
	int GetExamsCount();
	void IsPassed();
};