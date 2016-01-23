#pragma once
#include "stack.h"
using namespace std;

typedef void(*Method)(Trial*);

class TrialGroup
{
protected:
	int index;
	Stack stack;
public:
	TrialGroup();
	TrialGroup(Trial*);
	~TrialGroup();
	Trial *GetTop();
	void ForEach(Method);
	virtual void Add(Trial*);
	virtual void Delete();
	void Show();
	void HandleEvent(Event*);
};

class TestGroup : public TrialGroup
{
public:
	TestGroup();
	TestGroup(Test*);
	~TestGroup();
	virtual void Add(Test*);
	virtual void Delete();
};

class ExamGroup : public TrialGroup
{
public:
	ExamGroup();
	ExamGroup(Exam*);
	~ExamGroup();
	virtual void Add(Exam*);
	virtual void Delete();
};

class FinalExamGroup : public TrialGroup
{
public:
	FinalExamGroup();
	FinalExamGroup(FinalExam*);
	~FinalExamGroup();
	virtual void Add(FinalExam*);
	virtual void Delete();
};