#include<iostream> 
using namespace std; 

class vehicle 
{ 
	protected: 
	int wheels; 
	int weight; 
	public: 
	vehicle(int whe, int wei);
	void disp();
};

vehicle::vehicle(int whe, int wei)
{
	wheels = whe; 
	weight = wei; 
}
void vehicle::disp()
{ 
	cout << "wheels=" << wheels << ",weight=" << weight << endl; 
} 

class car:private vehicle 
{ 
	int passenger_load; 
	public: 
	car(int whe, int wei, int pas);
	void disp() 
	{ 
	cout <<"Ð¡³µ:"<<endl; 
	vehicle::disp(); 
	cout << "passenger_load=" << passenger_load << endl; 
	} 
}; 

car::car(int whe, int wei, int pas):vehicle(whe,wei)
{
	passenger_load = pas; 
}

class truck :private vehicle 
{ 
	int passenger_load; 
	int payload; 
	public: 
	truck(int whe, int wei, int pas,int pay) :vehicle(whe, wei) 
	{ 
	passenger_load = pas; 
	payload = pay; 
	} 
	void disp() 
	{ 
	cout <<"¿¨³µ:"<<endl; 
	vehicle::disp(); 
	cout << "passenger_load=" << passenger_load << "payload=" << payload << endl; 
	} 
}; 

int main() 
{ 
	vehicle v(10, 10); 
	v.disp(); 
	car c(20, 20, 20); 
	c.disp(); 
	truck t(30, 30, 30, 30); 
	t.disp(); 
	return 0;
}

