#include "stack.h"
#include "group.h"
#include "event.h"
#include <iostream>
using namespace std;

TrialGroup::TrialGroup()
{
	index = Constant.Group.Trial;
}

TrialGroup::TrialGroup(Trial *obj)
{
	index = grTrial;
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

void TrialGroup::HandleEvent(Event *_event)
{
	if (_event->IsValid())
	{

	}
}
//
//void MonarchyGroup::HandleEvent(Event *ev)
//{
//	if (ev->IsValid())
//	{
//		switch (ev->GetCommand())
//		{
//		case (grMonarchy * SHIFT + cmAdd) :
//		{
//			cout << "\n\n Enter country name:\n> ";
//			char *name = new char[LNAME];
//			cin.get();
//			cin.getline(name, LNAME);
//			cout << "\n Enter population:\n> ";
//			int population;
//			cin >> population;
//			cout << "\n Enter country area:\n> ";
//			double area;
//			cin >> area;
//			cout << "\n Enter monarchy type:\n> ";
//			char *type = new char[LNAME];
//			cin.get();
//			cin.getline(type, LNAME);
//
//			Monarchy *item = new Monarchy(name, population, area, type);
//			AddToGroup(item);
//			ev->ClearEvent();
//			break;
//		}
//		case (grMonarchy * SHIFT + cmPrint) :
//		{
//			Print();
//			ev->ClearEvent();
//			break;
//		}
//		case (grMonarchy * SHIFT + cmDelete) :
//		{
//			DeleteLast();
//			cout << " last element was deleted\n";
//			ev->ClearEvent();
//			break;
//		}
//		case (grMonarchy * SHIFT + cmForeach) :
//		{
//			pfList *temp = ev->pfLast;
//			while (temp)
//			{
//				ForEach(temp->pf);
//				temp = temp->next;
//			}
//			ev->ClearEvent();
//			break;
//		}
//		case (cmExit) :
//		{
//			ev->ClearEvent();
//			break;
//		}
//		}
//	}
//}


TestGroup::TestGroup()
{
	index = grTest;
}

TestGroup::TestGroup(Test *obj)
{
	index = grTest;
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
	index = grExam;
}

ExamGroup::ExamGroup(Exam *obj)
{
	index = grExam;
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
	index = grFinalExam;
}

FinalExamGroup::FinalExamGroup(FinalExam *obj)
{
	index = grFinalExam;
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