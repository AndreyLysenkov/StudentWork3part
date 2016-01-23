#include "group.h"
#include <iostream>
using namespace std;

TrialGroup::TrialGroup()
{
	index = Constant::Group::Trial;
}

TrialGroup::TrialGroup(Trial *obj)
{
	index = Constant::Group::Trial;
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

void TrialGroup::AddNew()
{
	Trial *obj = new Trial();
	obj->Enter();
	this->Add(obj);
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

void TrialGroup::HandleEvent(Event *_event)
{
	if (_event->IsValid())
	{
		int command = _event -> GetCommand();
		int cmAdd = Constant::BuildCommand(Constant::Command::Add, index);
		int cmPrint = Constant::BuildCommand(Constant::Command::Print, index);
		int cmForEach = Constant::BuildCommand(Constant::Command::ForEach, index);
		int cmDelete = Constant::BuildCommand(Constant::Command::Delete, index);
		if (command == cmAdd)
		{
			this->AddNew();
			_event->Clear();
		}
		if (command == cmPrint)
		{
			this->Show();
			_event->Clear();
		}
		if (command == cmForEach)
		{
			Event::MethodList *list = _event->methodList;
			while (list != NULL)
			{
				this->ForEach(list->method);
				list = list->next;
			}
			_event->Clear();
		}
		if (command == cmDelete)
		{
			this->Delete();
			_event->Clear();
		}
	}
}


TestGroup::TestGroup()
{
	index = Constant::Group::Test;
}

TestGroup::TestGroup(Test *obj)
{
	index = Constant::Group::Test;
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

void TestGroup::AddNew()
{
	Test *obj = new Test();
	obj->Enter();
	this->Add(obj);
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
	index = Constant::Group::Exam;
}

ExamGroup::ExamGroup(Exam *obj)
{
	index = Constant::Group::Exam;
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

void ExamGroup::AddNew()
{
	Exam *obj = new Exam();
	obj->Enter();
	this->Add(obj);
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
	index = Constant::Group::FinalExam;
}

FinalExamGroup::FinalExamGroup(FinalExam *obj)
{
	index = Constant::Group::FinalExam;
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

void FinalExamGroup::AddNew()
{
	FinalExam *obj = new FinalExam();
	obj->Enter();
	this->Add(obj);
}

void FinalExamGroup::Delete()
{
	if (typeid(stack.top) == typeid(FinalExam))
	{
		stack.Get();
	}
}