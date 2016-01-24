#include "user.h"
int Test::maxPoint = 100;
int Test::minPoint = 60;

Test::Test()
{
}

Test::Test(Test &)
{
}

Test::Test(char * b, int a = 10)
{
}

Test::~Test()
{
}

void Test::GainPoints(int)
{
}

const int Test::GetPoints()
{
	return 0;
}

const bool Test::IsPassed()
{
	return false;
}

const double Test::GetRating()
{
	return 0.0;
}

void Test::Set()
{
}

Test & Test::operator==(Test)
{
	// TODO: вставьте здесь оператор return
}

std::ostream & operator<<(ostream &, Test &)
{
	// TODO: вставьте здесь оператор return
}
