#include "user.h"

Test::Test()
{
	this->points = 0;
	this->maxPoints = 100;
}

Test::Test(int _points, int _maxPoints)
{
	this->points = _points;
	this->maxPoints = _maxPoints;
}

Test::Test(const Test &obj)
{
	this->points = obj.GetPoints();
	this->maxPoints = obj.GetMaxPoints();
}

int Test::GetPoints() const
{
	return this->points;
}

int Test::GetMaxPoints() const
{
	return this->maxPoints;
}

void Test::GainPoints(int _addPoints)
{
	this->points += _addPoints;
}

double Test::GetRating() const
{
	return (double)(this->points) / this->maxPoints;
}

void Test::Set(int _points, int _maxPoints)
{
	this->points = _points;
	this->maxPoints = _maxPoints;
}

bool Test::operator<(const Test &obj) const
{
	return this->GetRating() < obj.GetRating();
}

bool Test::operator>(Test obj)
{
	return this->GetRating() > obj.GetRating();
}

bool Test::operator==(Test obj)
{
	return this->GetRating() == obj.GetRating();
}

bool Test::operator!=(Test obj)
{
	return this->GetRating() != obj.GetRating();
}

Test& Test::operator=(const Test &obj)
{
	this->points = obj.GetPoints();
	this->maxPoints = obj.GetMaxPoints();
	return *this;
}

ostream& operator<<(ostream &stream, const Test &obj)
{
	stream << "(" << obj.GetRating() <<
		"=" << obj.GetPoints() <<
		"/" << obj.GetMaxPoints() << ")";
	return stream;
}

istream & operator>>(istream &stream, Test &obj)
{
	int _points, _maxPoints;
	stream >> _points >> _maxPoints;
	obj.Set(_points, _maxPoints);
	return stream;
}