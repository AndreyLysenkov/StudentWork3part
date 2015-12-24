#include "Trial.h"
#include <string>
#include <iostream>
using namespace std;


void main()
{
	cout << endl << "Trial -----" << endl;
	Trial Trial1,
		Trial2("3rd semester", "Math"),
		Trial3(Trial2);
	Trial1.Print();
	Trial2.Print();
	Trial3.Print();
	Trial1.SetName("1st semester");
	Trial1.SetSubject("Literature");
	Trial1.Print();
	Trial3.Print();

	cout << endl  << "Exam -----" << endl;
	Exam Exam1,
		Exam2("2nd semester 1st module", "Assembler"),
		Exam3(Exam2);
	Exam1.Print();
	Exam2.Print();
	Exam3.Print();
	Exam1.SetName("1st semester");
	Exam1.SetSubject("Programming");
	Exam1.SetMark(3);
	Exam1.Print();
	Exam3.Print();

	cout << endl << "FinalExam -----" << endl;
	FinalExam FinalExam1,
		FinalExam2("2nd semester 1st module", "Assembler"),
		FinalExam3(FinalExam2);
	FinalExam1.Print();
	FinalExam2.Print();
	FinalExam3.Print();
	FinalExam1.SetName("1st semester");
	FinalExam1.SetSubject("Programming");
	FinalExam1.SetMark(3);
	FinalExam1.Print();
	FinalExam3.Print();

	cout << endl << "Test -----" << endl;
	Test Test1,
		Test2("3rd semester", "Math", 55, 100, 60),
		Test3(Test1);
	Test1.Print();
	Test2.Print();
	Test3.Print();
	Test1.SetName("1st semester");
	Test1.SetSubject("Literature");
	Test1.Print();
	Test3.Print();

	int a;
	cin >> a;
}