#include "../include/Sedan.h"
#include <iostream>

Sedan::Sedan(const std::string &make, const std::string &model, int year, const std::string &licensePlate)
    : Car(make, model, year, licensePlate) {}

void Sedan::displayDetails() const
{
    std::cout << "Sedan Details: ";
    Vehicle::displayDetails();
}