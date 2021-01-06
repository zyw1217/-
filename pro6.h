#include <iostream>
using namespace std;
class vehicle{
private:
    int wheels;
    double weight;
public:
    vehicle(int wheels, double weight) {
        this->wheels = wheels;
        this->weight = weight;
    }

    int getWheels() const {
        return wheels;
    }

    void setWheels(int wheels) {
        vehicle::wheels = wheels;
    }

    double getWeight() const {
        return weight;
    }

    void setWeight(double weight) {
        vehicle::weight = weight;
    }

};

class car: private vehicle{
private:
    int passenger_load;
public:
    car(int wheels, double weight, int passenger_load):vehicle(wheels, weight){
        this->passenger_load = passenger_load;
    }
    int getPassengerLoad() const {
        return passenger_load;
    }

    void setPassengerLoad(int passengerLoad) {
        passenger_load = passengerLoad;
    }
    void outInfo(){
        cout << "weight=" << this->getWeight() <<" wheels=" << this->getWheels() << " passenger_load=" <<this->getPassengerLoad();
    }
};

class truck: private vehicle{
private:
    int passenger_load;
    double payload;
public:
    truck(int wheels, double weight, int passenger_load, double payload):vehicle(wheels, weight){
        this->passenger_load = passenger_load;
        this->payload = payload;
    }
    int getPassengerLoad() const {
        return passenger_load;
    }

    void setPassengerLoad(int passengerLoad) {
        passenger_load = passengerLoad;
    }

    double getPayload() const {
        return payload;
    }

    void setPayload(double payload) {
        truck::payload = payload;
    }
    void outInfo(){
        cout << "weight=" << this->getWeight() <<" wheels=" << this->getWheels()
             << " passenger_load=" <<this->getPassengerLoad()
             << " payload=" << this->getPayload();
    }
};
int main(){
    vehicle v(2, 5.0);
    cout << v.getWheels() << "\t" << v.getWeight();
    car c( 4, 2, 5);
    c.outInfo();
    cout << endl;
    truck t(8,8,2,10);
    t.outInfo();
    return 0;
}
