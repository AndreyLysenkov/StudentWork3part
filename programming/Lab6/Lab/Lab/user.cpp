#include "user.h"

int Test::maxPoint = 100;
int Test::minPoint = 60;

Test::Test()
{
	this->point = 0;
	this->subject = "undefinded";
}

Test::Test(Test &obj)
{
	this->point = obj.GetPoints();
	strcpy(this->subject, obj.GetSubject());
}

Test::Test(char * _subject, int _point = 0)
{
	this->subject = _subject;
	this->point = _point;
}

Test::~Test()
{
	delete this->subject;
}

void Test::GainPoints(int value)
{
	this->point += value;
}

const int Test::GetPoints()
{
	return this->point;
}

const char * Test::GetSubject()
{
	return this->GetSubject();
}

const bool Test::IsPassed()
{
	return (this->GetPoints()) >= (Test::minPoint);
}

const double Test::GetRating()
{
	return (this->GetPoints())/(double)(Test::maxPoint);
}

void Test::Set()
{

}

bool Test::operator==(Test)
{
	// TODO: вставьте здесь оператор return
}

std::ostream & operator<<(ostream &, Test &)
{
	// TODO: вставьте здесь оператор return
}

//State::State(State &country)
//{
//	name = new char[LNAME];
//	strcpy(name, country.GetName());
//	population = country.GetPopulation();
//	area = country.GetArea();
//}
//
//
//
//void State::SetName(char *_name)
//{
//	strcpy(name, _name);
//}
//
//
//void State::SetPopulation(int _population)
//{
//	population = _population;
//}
//
//
//
//void State::SetArea(double _area)
//{
//	area = _area;
//}
//
//
//void State::SetAll()
//{
//	cout << "\n Enter state name:  ";
//	cin.get();
//	cin.getline(name, LNAME);
//	cout << "\n Enter state population: ";
//	cin >> population;
//	cout << "\n Enter state area:  ";
//	cin >> area;
//}
//
//
//const char* State::GetName()
//{
//	return name;
//}
//
//
//int State::GetPopulation()
//{
//	return population;
//}
//
//
//double State::GetArea()
//{
//	return area;
//}
//
//
//
//
//
//bool State::operator==(State other)
//{
//	bool result = strcmp(this->GetName(), other.GetName()) == 0;
//	result = result && this->GetPopulation() == other.GetPopulation();
//	return result && this->GetArea() == other.GetArea();
//}
//
//State& State::operator=(const State &state)
//{
//	name = new char[LNAME];
//	strcpy(name, state.name);
//	population = state.population;
//	area = state.area;
//	return *this;
//}
//
//std::ostream& operator<<(ostream &stream, State &state)
//{
//	stream << " (" << state.GetName();
//	stream << ": population - " << state.GetPopulation();
//	stream << ", area - " << state.GetArea() << ") ";
//	return stream;
//}
//
