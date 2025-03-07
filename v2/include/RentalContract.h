#ifndef RENTALCONTRACT_H
#define RENTALCONTRACT_H

#include "Customer.h"
#include "Vehicle.h"
#include <string>

class RentalContract
{
private:
    Customer customer;
    Vehicle vehicle;
    std::string startDate;
    std::string endDate;
    double totalCost;

public:
    RentalContract(const Customer &customer, const Vehicle &vehicle, const std::string &startDate, const std::string &endDate, double totalCost);
    void displayContractDetails() const;
};

#endif // RENTALCONTRACT_H