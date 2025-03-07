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
    bool hasRented;

public:
    Vehicle(const std::string &make, const std::string &model, int year, const std::string &licensePlate);
    virtual ~Vehicle() = default;

    virtual void displayDetails() const;
    std::string getMake() const;
    std::string getModel() const;
    int getYear() const;
    std::string getLicensePlate() const;
    bool isAvailable() const;
    void setAvailable(bool hasRented);
};

#endif // VEHICLE_H