#include "../include/Car.h"
#include <iostream>

Car::Car(const std::string &make, const std::string &model, int year, const std::string &licensePlate)
    : Vehicle(make, model, year, licensePlate) {}

Car::~Car()
{
    // Destructor implementation (can be empty)
}

void Car::displayDetails() const
{
    std::cout << "Car Details: ";
    Vehicle::displayDetails();
}