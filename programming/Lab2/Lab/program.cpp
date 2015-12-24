#include "Trial.h"
#include "stack.h"
#include <string>
#include <iostream>
using namespace std;


void main()
{
	Stack stash;
	stash.Add(new Trial());
	stash.Add(new Test());
	stash.Add(new Exam());
	stash.Add(new FinalExam());
	stash.Show();
	cout << "deleting 1st one -----" << endl;
	stash.Get();
	stash.Show();
	cout << "adding one of them" << endl;
	stash.Add(new Trial("Web-programming", "1st half"));
	stash.Show();
	int a;
	cin >> a;
}