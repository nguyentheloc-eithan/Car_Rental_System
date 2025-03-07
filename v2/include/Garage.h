#ifndef GARAGE_H
#define GARAGE_H

#include "Vehicle.h"
#include <list>
#include <string>

class Garage
{
private:
    std::list<Vehicle *> vehicles;

public:
    void addVehicle(Vehicle *vehicle);
    void displayAllVehicles() const;
    Vehicle *findVehicleByLicensePlate(const std::string &licensePlate);
    void saveToFile(const std::string &filename) const;
    void loadFromFile(const std::string &filename);
};

#endif // GARAGE_H