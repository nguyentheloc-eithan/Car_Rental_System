#ifndef GARAGE_H
#define GARAGE_H

#include "Vehicle.h"
#include <list>

class Garage
{
private:
    std::list<Vehicle *> vehicles;

public:
    void addVehicle(Vehicle *vehicle);
    void displayAllVehicles() const;
};

#endif // GARAGE_H