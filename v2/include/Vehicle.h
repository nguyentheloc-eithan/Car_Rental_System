#ifndef VEHICLE_H
#define VEHICLE_H

#include "Service.h"
#include <string>
#include <list>

class Vehicle
{
protected:
    std::string make;
    std::string model;
    int year;
    std::string licensePlate;
    std::list<Service> serviceHistory; // List of services performed on the vehicle

public:
    Vehicle(const std::string &make, const std::string &model, int year, const std::string &licensePlate);
    virtual ~Vehicle() = default;

    virtual void displayDetails() const;
    std::string getLicensePlate() const;

    void addService(const Service &service);
    void displayServiceHistory() const;
};

#endif // VEHICLE_H