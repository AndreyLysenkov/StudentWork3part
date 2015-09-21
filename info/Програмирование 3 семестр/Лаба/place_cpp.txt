#include "place.h";
#include<iostream>;
#include<string.h>;

using namespace std;

Spot::Spot()
{
	x = 0;
	y = 0;
}

Spot::Spot(int _x, int _y)
{
	x = _x;
	y = _y;
}

Spot::Spot(Spot& _spot)
{
	x = _spot.GetX();
	y = _spot.GetY();
}

Spot::~Spot()
{
	cout << "PLace dead " << x << " " << y << "!" << endl;
}

void Spot::SetX(int _x)
{
	x = _x;
}

void Spot::SetY(int _y)
{
	y = _y;
}

int Spot::GetX()
{
	return x;
}

int Spot::GetY()
{
	return y;
}

Region::Region() : Spot()
{
	regionId = 0;
	regionName = "";
}

Region::Region(int _x, int _y, int _regionId, string _regionName)
	:Spot(_x,_y)
{
	regionId = _regionId;
	regionName = _regionName;
}

Region::Region(Region& _obj) :Spot(_obj.GetX(), _obj.GetY())
{
	regionId = _obj.GetRegionId();
	regionName = _obj.GetRegionName();
}

Region::~Region()
{
	cout << "Region dead " << &regionName << "!" << endl;
}

int Region::GetRegionId()
{
	return regionId;
}

string Region::GetRegionName()
{
	return regionName;
}

void Region::SetRegionId(int _id)
{
	regionId = _id;
}

void Region::SetRegionName(string _name)
{
	regionName = _name;
}

City::City() :Region()
{
	name = "";
}

City::City(int _x, int _y, int _regionId, string _regionName, string _name)
	: Region(_x, _y, _regionId, _regionName)
{
	name = _name;
}

//City::City(City& _obj)
//	:Region(_obj.GetX(), _obj.GetY(), _obj.GetRegionId(), _obj.GetRegionName())
//{
//	name = _obj.GetName();
//}

City::~City()
{
	cout << "City " << &name << " dead!";
}

void City::SetName(string _name)
{
	name = _name;
}

string City::GetName()
{
	return name;
}

Megapolis::Megapolis() :City()
{
	lolita = true;
	cout << "Lolita into MEGAPOLIS '" << &name << "'!" << endl;
}

Megapolis::Megapolis(int _x, int _y, int _regionId, string _regionName, string _name) 
	:City(_x, _y, _regionId, _regionName, _name)
{
	lolita = true;
	cout << "Lolita into MEGAPOLIS '" << &name << "'!" << endl;
}

//Megapolis::Megapolis(Megapolis& _obj)
//	:City(_obj.GetX(), _obj.GetY(), _obj.GetRegionId(), _obj.GetRegionName(), _obj.GetName())
//{
//	lolita = true;
//	cout << "Lolita into MEGAPOLIS '" << name << "'!" << endl;
//}

Megapolis::~Megapolis()
{
	cout << "Megapolis " << &name << " dead!";
}