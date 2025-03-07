#include "../include/Van.h"
#include <iostream>

Van::Van(const std::string &make, const std::string &model, int year, const std::string &licensePlate)
    : Car(make, model, year, licensePlate) {}

void Van::displayDetails() const
{
    std::cout << "Van Details: ";
    Vehicle::displayDetails();
}