#include "place.h";
#include<iostream>;

using namespace std;

int LENGTH = 10;

Spot::Spot()
{
	x = 0;
	y = 0;
	cout<<"Was set X=0, Y=0"<<endl;
}

Spot::Spot(int _x, int _y)
{
	x = _x;
	y = _y;
	cout<<"Was set X="<<x<<", Y="<<y<<endl;
}

Spot::Spot(Spot& _spot)
{
	x = _spot.GetX();
	y = _spot.GetY();
	cout<<"Was copy X="<<x<<", Y="<<y<<endl;
}

Spot::~Spot()
{
	cout << "Spot dead " << x << " " << y << "!" << endl;
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

	cout<<"Was set 0 region id"<<endl;
}

Region::Region(int _x, int _y, int _regionId)
	:Spot(_x,_y)
{
	regionId = _regionId;
	cout<<"Was set '"<<regionId<<"' region id"<<endl;
}

Region::Region(Region& _obj) : Spot(_obj.GetX(), _obj.GetY())
{
	regionId = _obj.GetRegionId();
	cout<<"Was copy '"<<regionId<<"' region id"<<endl;
}

Region::~Region()
{
	cout << "Region dead " << regionId << "!" << endl;
}

int Region::GetRegionId()
{
	return regionId;
}

void Region::SetRegionId(int _id)
{
	regionId = _id;
}


City::City() :Spot()
{
	name = new char[LENGTH];
	strcpy(name,"");
	cout<<"Was set null city name"<<endl;
}

City::City(int _x, int _y, char* _name)
	: Spot(_x, _y)
{
	name = new char[LENGTH];
	strcpy(name,_name);
    cout<<"Was set '"<<name<<"' city name"<<endl;
}

City::City(City& _obj)
	: Spot(_obj.GetX(), _obj.GetY())
{
	name = new char[LENGTH];
	strcpy(name,_obj.GetName());
	cout<<"Was copy '"<<name<<"' city name"<<endl;
}

City::~City()
{
	cout << "City " << name << " dead!" << endl;;
}

void City::SetName(char* _name)
{
		name = new char[LENGTH];
	    strcpy(name,_name);
}

char* City::GetName()
{
	return name;
}

Megapolis::Megapolis() :City()
{
	cout<<"Was set megapolis name"<<endl;
}

Megapolis::Megapolis(int _x, int _y, char* _name, int _countPeople) 
	:City(_x, _y, _name)
{
	countPeople = _countPeople;
	cout<<"Was set parametrs megapolis name"<<endl;
}

Megapolis::Megapolis(Megapolis& _obj)
:City(_obj.GetX(), _obj.GetY(), _obj.GetName())
{
	countPeople = _obj.GetPeoples();
	cout<<"Was copy megapolis name"<<endl;
}

int Megapolis::GetPeoples()
{
	return countPeople;
}

Megapolis::~Megapolis()
{
	cout << "Megapolis " << name << " dead!" <<endl;
}