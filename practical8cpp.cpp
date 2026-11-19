#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Vehicle
{
public:
    virtual void start() = 0;
    virtual ~Vehicle() = default;
};

class Car : public Vehicle
{
public:
    void start() override
    {
        cout << "Car engine starts.\n";
    }
};

class Bike : public Vehicle
{
public:
    void start() override
    {
        cout << "Bike engine starts.\n";
    }
};

class VehicleCreator
{
public:
    static unique_ptr<Vehicle> createVehicle(const string &type)
    {
        if (type == "Car")
        {
            return make_unique<Car>();
        }
        else if (type == "Bike")
        {
            return make_unique<Bike>();
        }
        else
        {
            return nullptr;
        }
    }
};

int main()
{
    cout << "Student name: SAMEERA MANKAR\n";
    cout << "URN: E25B000297\n\n";

    unique_ptr<Vehicle> a = VehicleCreator::createVehicle("Car");
    if (a)
    {
        a->start();
    }

    unique_ptr<Vehicle> b = VehicleCreator::createVehicle("Bike");
    if (b)
    {
        b->start();
    }

    return 0;
}

