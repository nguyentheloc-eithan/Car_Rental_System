#ifndef CARRENTALSYSTEM_H
#define CARRENTALSYSTEM_H

#include "Garage.h"
#include "RentalContract.h"
#include <list>

class CarRentalSystem
{
private:
    Garage garage;
    std::list<RentalContract> contracts;

public:
    void addVehicleToGarage(Vehicle *vehicle);
    void rentVehicle(const Customer &customer, Vehicle *vehicle, const std::string &startDate, const std::string &endDate, double totalCost);
    void displayAllContracts() const;
    Vehicle *findVehicleByLicensePlate(const std::string &licensePlate); // New method
};

#endif // CARRENTALSYSTEM_H