#include "user.h"

ostream & operator<<(ostream &, Test &)
{
	// TODO: �������� ����� �������� return
}

istream & operator>>(istream &, Test &)
{
	// TODO: �������� ����� �������� return
}

Test::Test()
{
}

Test::Test(char *, int)
{
}

Test::Test(const Test &)
{
}

char * Test::GetSubject()
{
	return nullptr;
}

int Test::GetPoints()
{
	return 0;
}

int Test::GainPoints(int)
{
	return 0;
}

bool Test::operator<(Test)
{
	return false;
}

bool Test::operator>(Test)
{
	return false;
}

bool Test::operator==(Test)
{
	return false;
}

bool Test::operator!=(Test)
{
	return false;
}

Test & Test::operator=(const Test &)
{
	// TODO: �������� ����� �������� return
}
