#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle
{
public:
    Car(const std::string &make, const std::string &model, int year, const std::string &licensePlate);
    void displayDetails() const override;
};

#endif // CAR_H