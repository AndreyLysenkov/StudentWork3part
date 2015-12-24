#include <string>
using namespace std;

class Trial
{
protected:
	char *subject;
	char *name;
public:
	Trial();
	Trial(Trial&);
	Trial(char*, char*);
	~Trial();
	void SetSubject(char*);
	void SetName(char*);
	char *GetSubject();
	char *GetName();
	int GainScore(int);
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
	Test(char *, char*, int, int, int);
	~Test();
	void SetScore(int);
	int GetScore();
	int GetMaxScore();
	int GetMinScore();
	double GetRating();
	int GainScore(int);
	double GetMinRating();
};

class Exam : public Trial
{
protected:
	int mark;
	bool isPassed;
public:
	Exam();
	Exam(Exam&);
	Exam(char*, char*);
	~Exam();
	int GetMark();
	bool SetMark(int);
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
	FinalExam(char*, char*);
	~FinalExam();
	bool IsAccessed();
	void GainAccess();
	void SetFinalMark(int, int[], int);
	int GetFinalMark();
};