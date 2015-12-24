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


//		cout << country1.getname() << ",  " << country1.getpopulation() << ",  s=" << country1.getarea() << ",  " << country1.gettype() << endl;
//	}
//	{
//		kingdom country1, country2("strana 8", 3333, 14.234, "absolute", "dynasty_name"), country3(country1);
//		cout << country1.getname() << ",  " << country1.getpopulation() << ",  s=" << country1.getarea() << ",  " << country1.gettype() << ",  " << country1.getdynasty() << endl;
//		cout << country2.getname() << ",  " << country2.getpopulation() << ",  s=" << country2.getarea() << ",  " << country2.gettype() << ",  " << country2.getdynasty() << endl;
//		cout << country3.getname() << ",  " << country3.getpopulation() << ",  s=" << country3.getarea() << ",  " << country3.gettype() << ",  " << country3.getdynasty() << endl;
//		country1.setname("strana7");
//		country1.setpopulation(2912);
//		country1.setarea(465.364);
//		country1.settype("parlament");
//		country1.setdynasty("d_name");
//		cout << country1.getname() << ",  " << country1.getpopulation() << ",  s=" << country1.getarea() << ",  " << country1.gettype() << ",  " << country1.getdynasty() << endl;
//	}
//	{
//		republic country1, country2("strana 5", 2222, 23.271, "parlament"), country3(country1);
//		cout << country1.getname() << ",  " << country1.getpopulation() << ",  s=" << country1.getarea() << ",  " << country1.gettype() << endl;
//		cout << country2.getname() << ",  " << country2.getpopulation() << ",  s=" << country2.getarea() << ",  " << country2.gettype() << endl;
//		cout << country3.getname() << ",  " << country3.getpopulation() << ",  s=" << country3.getarea() << ",  " << country3.gettype() << endl;
//		country1.setname("strana10");
//		country1.setpopulation(2912);
//		country1.setarea(465.364);
//		country1.settype("president");
//		cout << country1.getname() << ",  " << country1.getpopulation() << ",  s=" << country1.getarea() << ",  " << country1.gettype() << endl;
//	}
//	return 0;
//}

