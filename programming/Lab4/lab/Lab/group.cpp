#include "stdafx.h"
#include "stack.h"
#include "group.h"
#include <iostream>
using namespace std;

TrialGroup::TrialGroup()
{

}

TrialGroup::TrialGroup(Trial *obj)
{
	Add(obj);
}

TrialGroup::~TrialGroup()
{

}

void TrialGroup::Add(Trial *obj)
{
	if (typeid(*obj) == typeid(Trial))
	{
		stack.Add(obj);
	}
}

void TrialGroup::ForEach(Method method)
{
	Element *tmp = stack.top;
	if (tmp == NULL)
	{
		cout << "No elements";
	}
	for (int i = 0; tmp != NULL; i++)
	{
		method(tmp->obj);
		tmp = tmp->next;
	}
}

void TrialGroup::Show()
{
	stack.Show();
}

void TrialGroup::Delete()
{
	if (typeid(stack.top) == typeid(Trial))
	{
		stack.Get();
	}
}

Trial *TrialGroup::GetTop()
{
	return stack.top->obj;
}


TestGroup::TestGroup()
{

}

TestGroup::TestGroup(Test *obj)
{
	Add(obj);
}

TestGroup::~TestGroup()
{

}

void TestGroup::Add(Test *obj)
{
	if (typeid(*obj) == typeid(Test))
	{
		stack.Add(obj);
	}
}

void TestGroup::Delete()
{
	if (typeid(stack.top) == typeid(Test))
	{
		stack.Get();
	}
}


ExamGroup::ExamGroup()
{

}

ExamGroup::ExamGroup(Exam *obj)
{
	Add(obj);
}

ExamGroup::~ExamGroup()
{

}

void ExamGroup::Add(Exam *obj)
{
	if (typeid(*obj) == typeid(Exam))
	{
		stack.Add(obj);
	}
}

void ExamGroup::Delete()
{
	if (typeid(stack.top) == typeid(Exam))
	{
		stack.Get();
	}
}


FinalExamGroup::FinalExamGroup()
{

}

FinalExamGroup::FinalExamGroup(FinalExam *obj)
{
	Add(obj);
}

FinalExamGroup::~FinalExamGroup()
{

}

void FinalExamGroup::Add(FinalExam *obj)
{
	if (typeid(*obj) == typeid(FinalExam))
	{
		stack.Add(obj);
	}
}

void FinalExamGroup::Delete()
{
	if (typeid(stack.top) == typeid(FinalExam))
	{
		stack.Get();
	}
}