#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <list>

class Vehicle
{
protected:
    std::string make;
    std::string model;
    int year;
    std::string licensePlate;

public:
    Vehicle(const std::string &make, const std::string &model, int year, const std::string &licensePlate);
    virtual ~Vehicle() = default;

    virtual void displayDetails() const;
    std::string getLicensePlate() const;
};

#endif // VEHICLE_H