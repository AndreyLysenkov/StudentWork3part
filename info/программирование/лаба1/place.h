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

class Region : public Spot
{
protected:
	int regionId;
public:
	Region();
	Region(int, int, int);
	Region(Region&);
	~Region();
	void SetRegionId(int);
	int GetRegionId();
};

class City : public Spot
{
protected:
	char* name;
public:
	City();
	City(int, int, char*);
	City(City&);
	~City();
	void SetName(char*);
	char* GetName();
};

class Megapolis : public City
{
private:
	int countPeople;
public:
	Megapolis();
	Megapolis(int, int, char*, int);
	Megapolis(Megapolis&);
int GetPeoples();
	~Megapolis();
};
#endif