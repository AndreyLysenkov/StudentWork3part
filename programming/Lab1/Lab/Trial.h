#include <string>
using namespace std;

class Trial
{
protected:
	char *subject;
	char *name;
	int score;
public:
	Trial();
	Trial(Trial&);
	Trial(char*, char*, int);
	~Trial();
	void SetSubject(char*);
	void SetScore(int);
	void SetName(char*);
	char *GetSubject();
	char *GetName();
	int GetScore();
	int GainScore(int);
};

class Test : public Trial
{
protected:
	int maxScore;
	int minScore;
public:
	Test();
	Test(Test&);
	Test(char *, char*, int, int, int);
	Test(char *, char*, int, int);
	Test(char *, char*);
	~Test();
	double GetRating();
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
	bool IsAccessed();
	void GainAccessed();
	void SetFinalMark(int);
};