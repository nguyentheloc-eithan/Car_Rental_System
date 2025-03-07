#include "../include/Garage.h"
#include "../include/Vehicle.h"

void Garage::addVehicle(Vehicle *vehicle)
{
    vehicles.push_back(vehicle);
}

void Garage::displayAllVehicles() const
{
    for (const auto &vehicle : vehicles)
    {
        vehicle->displayDetails();
    }
}