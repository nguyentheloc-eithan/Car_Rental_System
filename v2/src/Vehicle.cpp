#include "../include/Vehicle.h"
#include <iostream>

Vehicle::Vehicle(const std::string &make, const std::string &model, int year, const std::string &licensePlate)
    : make(make), model(model), year(year), licensePlate(licensePlate) {}

void Vehicle::displayDetails() const
{
    std::cout << "Make: " << make << ", Model: " << model << ", Year: " << year << ", License Plate: " << licensePlate << std::endl;
}

std::string Vehicle::getLicensePlate() const
{
    return licensePlate;
}