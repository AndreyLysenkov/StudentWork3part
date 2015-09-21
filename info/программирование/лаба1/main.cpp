#include "place.h";
#include<Windows.h>;
#include<iostream>;

using namespace std;

void main()

{	cout<<"\nCONSTRUCTORS:"<<endl;
	cout<<"-------------------Spot"<<endl;
	Spot spot;
	cout<<"-------------------Region"<<endl;
	Region region;
	cout<<"-------------------City"<<endl;
	City city;
	cout<<"-------------------Megapolis"<<endl;
	Megapolis megapolis;

	int x,y,id;
	char *name = new char[10];

	cout<<"\nCONSTRUCTORS WITH PARAMETRS:"<<endl;
	cout<<"-------------------Spot"<<endl;
	cout<<"type x,y: ";
	cin>>x>>y;
	Spot spot2(x,y);

	cout<<"-------------------Region"<<endl;
	cout<<"type x,y,id region: ";
	cin>>x>>y>>id;
	Region region2(x,y,id);

	cout<<"-------------------City"<<endl;
	cout<<"type x,y,name: ";
	cin>>x>>y>>name;
	City city2(x,y,name);

	cout<<"-------------------Megapolis"<<endl;
	cout<<"type x,y, name megapolis, count peoples: ";
	cin>>x>>y>>name>>id;
	Megapolis megapolis2(x,y,name,id);

	cout<<"\nCONSTRUCTORS COPY:"<<endl;
	cout<<"-------------------Spot"<<endl;
	Spot spot3(spot2);
	cout<<"-------------------Region"<<endl;
	Region region3(region2);
	cout<<"-------------------City"<<endl;
	City city3(city2);
	cout<<"-------------------Megapolis"<<endl;
	Megapolis megapolis3(megapolis2);


	
	cout<<"\nDISTRUCTORS:"<<endl;;
	cout<<"-------------------Spot"<<endl;
	spot2.~Spot();
	cout<<"-------------------Region"<<endl;
	region2.~Region();
	cout<<"-------------------City"<<endl;
	city2.~City();
	cout<<"-------------------Megapolis"<<endl;
	megapolis2.~Megapolis();

	system("pause");
}