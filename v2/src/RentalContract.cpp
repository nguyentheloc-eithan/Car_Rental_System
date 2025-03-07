#include "../include/RentalContract.h"
#include <iostream>

RentalContract::RentalContract(const Customer &customer, const Vehicle &vehicle, const std::string &startDate, const std::string &endDate, double totalCost)
    : customer(customer), vehicle(vehicle), startDate(startDate), endDate(endDate), totalCost(totalCost) {}

void RentalContract::displayContractDetails() const
{
    customer.displayServiceHistory();
    vehicle.displayDetails();
    std::cout << "Rental Period: " << startDate << " to " << endDate << std::endl;
    std::cout << "Total Cost: $" << totalCost << std::endl;
}