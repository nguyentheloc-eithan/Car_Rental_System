#ifndef Van_H
#define Van_H

#include "Car.h"

class Van : public Car
{
public:
    Van(const std::string &make, const std::string &model, int year, const std::string &licensePlate);
    void displayDetails() const override;
};

#endif // Van_H