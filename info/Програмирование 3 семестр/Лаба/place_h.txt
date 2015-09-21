#include"stdafx.h";
using namespace std;

#ifndef Place

#define Place

class Spot
{
protected:
	int x, y;
public:
	Spot();
	Spot(int, int);
	Spot(Spot&);
	~Spot();
	void SetX(int);
	void SetY(int);
	int GetX();
	int GetY();
};

class Region : Spot
{
protected:
	int regionId;
	string regionName;
public:
	Region();
	Region(int, int, int, string);
	Region(Region&);
	~Region();
	void SetRegionName(string);
	void SetRegionId(int);
	int GetRegionId();
	string GetRegionName();
};

class City : Region
{
protected:
	string name;
public:
	City();
	City(int, int, int, string, string);
	//City(City&);
	~City();
	void SetName(string);
	string GetName();
};

class Megapolis : City
{
private:
	bool lolita;
public:
	Megapolis();
	Megapolis(int, int, int, string, string);
	//Megapolis(Megapolis&);
	~Megapolis();
};
#endif