#include <iostream>

using namespace std;

class Wheels 
{
protected:
    int numberOfWheels;
public:
    Wheels(int num) : numberOfWheels(num) {}
    void display() const 
    {
        cout << "Number of wheels: " << numberOfWheels << endl;
    }
};

class Engine 
{
protected:
    string type;
public:
    Engine(const string& t) : type(t) {}
    void display() const 
    {
        cout << "Engine type: " << type << endl;
    }
};

class Doors 
{
protected:
    int numberOfDoors;
public:
    Doors(int num) : numberOfDoors(num) {}
    void display() const 
    {
        cout << "Number of doors: " << numberOfDoors << endl;
    }
};

class Car : public Wheels, public Engine, public Doors 
{
public:
    Car(int wheels, const string& engineType, int doors) : Wheels(wheels), Engine(engineType), Doors(doors) {}

    void display() const 
    {
        Wheels::display();
        Engine::display();
        Doors::display();
    }
};

int main() 
{
    Car myCar(4, "V8", 4);
    cout << "My car details:" << endl;
    myCar.display();

    return 0;
}
