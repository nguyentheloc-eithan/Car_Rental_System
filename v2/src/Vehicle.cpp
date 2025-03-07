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

void Vehicle::addService(const Service &service)
{
    serviceHistory.push_back(service);
}

void Vehicle::displayServiceHistory() const
{
    std::cout << "Service History for Vehicle (" << licensePlate << "):" << std::endl;
    for (const auto &service : serviceHistory)
    {
        service.displayServiceDetails();
        std::cout << "-------------------" << std::endl;
    }
}