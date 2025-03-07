#ifndef SUV_H
#define SUV_H

#include "Car.h"

class SUV : public Car
{
public:
    SUV(const std::string &make, const std::string &model, int year, const std::string &licensePlate);
    void displayDetails() const override;
};

#endif // SUV_H