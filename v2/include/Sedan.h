#ifndef Sedan_H
#define Sedan_H

#include "Car.h"

class Sedan : public Car
{
public:
    Sedan(const std::string &make, const std::string &model, int year, const std::string &licensePlate);
    void displayDetails() const override;
};

#endif // Sedan_H