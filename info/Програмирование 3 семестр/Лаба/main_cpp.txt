#include "place.h";
#include<Windows.h>
#include <iostream>;

using namespace std;

void main()
{
	Spot *spot = new Spot();
	Region *region =  new Region();
	City *city = new City();
	Megapolis *megapolis = new Megapolis();

	delete spot,region,city,megapolis;

	system("pause");
}