#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
#include<string>
class vehicle
{
protected :
	string name;
	int wheels;
	float weight;
public:
	vehicle(int wh,float we):wheels(wh),weight(we){}
	void setwheels(int wh) { wheels = wh; }
	void setweight(float we) { weight = we; }
	int getwheels(){return wheels;}
	float getweight(){return weight;}
	void print()const;
};
void vehicle::print()const
{
	cout << "车轮数：" << wheels << endl;
	cout << "重量（吨）：" << weight << endl;
}
class truck :private vehicle
{
protected:
	int passenger_load;
	float payload;
public:
    truck(int wh, float we,int pas, float pay) :vehicle(wh, we),passenger_load (pas), payload(pay) {}
	void setpassenger_load(int pas){passenger_load=pas;}
	void setpayload(float pay){payload=pay;}
	int getpassenger_load(){return passenger_load;}
	float getpayload(){return payload;}
	void print()const;
};
void truck::print()const
{
	cout << "卡车车轮个数：" << wheels << endl;
	cout << "卡车载人数：" << passenger_load << endl;
	cout << "卡车载重量（吨）：" << payload<< endl;
	cout << "卡车重量（吨）：" << weight << endl;
}
class car :private vehicle
{
protected:
	int passenger_load;
public:
	car(int pas,int wh,float we):vehicle(wh, we),passenger_load(pas){}
	void setpassenger_load(int pas){passenger_load=pas;}
	int getpassenger_load(){return passenger_load;}
	void print()const;
};
void car::print()const
{
	cout << "小车车轮个数：" << wheels << endl;
	cout << "小车载人数：" << passenger_load << endl;
	cout << "小车重量（吨）：" << weight << endl;
}	
int main()
{
    vehicle vehiclecl(4,500);
    vehiclecl.print();
	car carqc(4, 4, 500);
	carqc.print();
	truck truckkc(4,5,4,500);
	truckkc.print();
    system("PAUSE");
	return 0;
}
