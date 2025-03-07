#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle
{
public:
    Car(const std::string &make, const std::string &model, int year, const std::string &licensePlate);
    virtual ~Car(); // Add a virtual destructor
    void displayDetails() const override;
};

#endif // CAR_H