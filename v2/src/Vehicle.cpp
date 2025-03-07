#include "../include/Vehicle.h"
#include <iostream>

Vehicle::Vehicle(const std::string &make, const std::string &model, int year, const std::string &licensePlate)
    : make(make), model(model), year(year), licensePlate(licensePlate), hasRented(true) {}

void Vehicle::displayDetails() const
{
    std::cout << "Make: " << make << ", Model: " << model << ", Year: " << year
              << ", License Plate: " << licensePlate << ", Available: " << (this->isAvailable() ? "Yes" : "No") << "\n";
}

std::string Vehicle::getMake() const
{
    return make;
}

std::string Vehicle::getModel() const
{
    return model;
}

int Vehicle::getYear() const
{
    return year;
}

std::string Vehicle::getLicensePlate() const
{
    return licensePlate;
}

bool Vehicle::isAvailable() const
{
    return this->hasRented;
}

void Vehicle::setAvailable(bool available)
{
    this->hasRented = available;
}