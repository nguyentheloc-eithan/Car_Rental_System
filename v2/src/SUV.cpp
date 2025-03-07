#include "../include/SUV.h"
#include <iostream>

SUV::SUV(const std::string &make, const std::string &model, int year, const std::string &licensePlate)
    : Car(make, model, year, licensePlate) {}

void SUV::displayDetails() const
{
    std::cout << "SUV Details: ";
    Vehicle::displayDetails();
}