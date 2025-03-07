#include "../include/CarRentalSystem.h"
#include "../include/Vehicle.h"
#include "../include/Customer.h"
#include "../include/RentalContract.h"

void CarRentalSystem::addVehicleToGarage(Vehicle *vehicle)
{
    garage.addVehicle(vehicle);
}

void CarRentalSystem::rentVehicle(const Customer &customer, Vehicle *vehicle, const std::string &startDate, const std::string &endDate, double totalCost)
{
    RentalContract contract(customer, *vehicle, startDate, endDate, totalCost);
    contracts.push_back(contract);
}

void CarRentalSystem::displayAllContracts() const
{
    for (const auto &contract : contracts)
    {
        contract.displayContractDetails();
    }
}

Vehicle *CarRentalSystem::findVehicleByLicensePlate(const std::string &licensePlate)
{
    return garage.findVehicleByLicensePlate(licensePlate);
}