#include <iostream>
#include <vector>
using namespace std;
class Vehicle{
protected:
    string name;
    int speed;
    int capacity;
public:
    Vehicle(string n,int s,int c){
        name=n;
        speed=s;
        capacity=c;
    }
    virtual int fare(int distance)=0; // pure virtual function 

    void start(){
        cout<<name<<" is starting."<<endl;
    }

    void stop(){
        cout<<name<<" has stopped."<<endl;
    }

    string getName(){
        return name;
    }
};

class Car:public Vehicle{
public:
    Car(string n, int s, int c):Vehicle(n, s, c){}

    int fare(int distance)override{
        int base_fare=50;
        return base_fare+distance*10;
    }
};

class Bus:public Vehicle{
public:
    Bus(string n,int s,int c):Vehicle(n,s,c){}

    int fare(int distance)override{
        int base_fare=100;
        return base_fare+distance*20;
    }
};

class Bike:public Vehicle {
public:
    Bike(string n,int s,int c):Vehicle(n,s,c){}

    int fare(int distance)override{
        int base_fare = 20;
        return base_fare+distance*5;
    }
};

int main(){
    int distance=10;
    vector<Vehicle*> vehicles;

    vehicles.push_back(new Car("Honda Civic",180,5));
    vehicles.push_back(new Bus("Daewoo Bus",120,40));
    vehicles.push_back(new Bike("Yamaha Bike",140,2));

    for (auto v:vehicles) {
        v->start();
        cout<<v->getName()<<" fare for "<<distance<<" km: ";
        cout<< v->fare(distance)<<endl;
        v->stop();
        cout<<"-----------------------------------"<<endl;
    }


    for (auto v:vehicles){
        delete v;
    }
    return 0;
}
