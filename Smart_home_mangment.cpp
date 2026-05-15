#include <iostream>
#include <string>
using namespace std;

// ================= BASE CLASS =================
class Device{
protected:
    string deviceName;
    bool status;

public:
    // Constructor
    Device(string name){
        deviceName=name;
        status=false;
    }

    // Encapsulation
    void turnOn(){
        status=true;
    }

    void turnOff(){
        status=false;
    }

    string getStatus(){
        return status?"ON":"OFF";
    }

    // Pure Virtual Function (Abstraction)
    virtual void display()=0;

    // Virtual Destructor
    virtual~Device(){}
};

// ================= DERIVED CLASS =================
class Light:public Device{
private:
    int brightness;
public:
    Light(string name,int b):Device(name){
        brightness=b;
    }
    void display()override{
        cout<<"\n--- Light Device ---"<<endl;
        cout<<"Name: " << deviceName<<endl;
        cout<<"Status: " << getStatus()<<endl;
        cout<<"Brightness: " << brightness<<"%"<<endl;
    }
};
// ================= DERIVED CLASS =================
class Fan:public Device{
private:
    int speed;
public:
    Fan(string name,int s):Device(name){
        speed=s;
    }
    void display()override{
        cout<<"\n--- Fan Device ---"<<endl;
        cout<<"Name: "<<deviceName<<endl;
        cout<<"Status: "<<getStatus()<<endl;
        cout<<"Speed Level: "<<speed<<endl;
    }
};

// ================= DERIVED CLASS =================
class AC:public Device{
private:
    int temperature;
public:
    AC(string name,int temp):Device(name) {
        temperature=temp;
    }

    void display()override{
        cout<<"\n--- Air Conditioner ---"<<endl;
        cout<<"Name: "<<deviceName<<endl;
        cout<<"Status: "<<getStatus()<<endl;
        cout<<"Temperature: "<<temperature<<" C"<<endl;
    }
};
// ================= MAIN FUNCTION =================
int main(){
    // Polymorphism using array of base class pointers
    Device*devices[3];

    devices[0]=new Light("Bedroom Light",80);
    devices[1]=new Fan("Ceiling Fan",5);
    devices[2]=new AC("Samsung AC",22);
    // Turn ON all devices
    for (int i=0;i<3;i++){
        devices[i]->turnOn();
    }
    // Display all devices
    for (int i=0;i<3;i++) {
        devices[i]->display();
    }
    // Memory Cleanup
    for (int i=0;i<3;i++) {
        delete devices[i];
    }
    return 0;
}
