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

 double calculateDynamicPricing(Vehicle *vehicle, const std::string &startDate, const std::string &endDate)
    {
        // Placeholder logic for dynamic pricing
        double basePrice = vehicle->getDailyRate();
        int rentalDuration = calculateRentalDuration(startDate, endDate);
        double demandMultiplier = getDemandMultiplier(startDate); // Assume this method exists
        return basePrice * rentalDuration * demandMultiplier;
    }

    // Helper method to calculate rental duration in days
    int calculateRentalDuration(const std::string &startDate, const std::string &endDate)
    {
        // Placeholder logic for date calculation (use a proper date library in real implementation)
        return 5; // Example: 5 days
    }

    // Helper method to apply loyalty discounts
    double applyLoyaltyDiscount(const Customer &customer, double totalCost)
    {
        if (customer.getLoyaltyPoints() > 1000)
        {
            return totalCost * 0.9; // 10% discount for loyal customers
        }
        return totalCost;
    }

void rentVehicleComplex(const Customer &customer, Vehicle *vehicle, const std::string &startDate, const std::string &endDate)
    {
        // Check if the vehicle is available
        if (!garage.isVehicleAvailable(vehicle))
        {
            throw std::runtime_error("Vehicle is not available for the selected dates.");
        }

        // Calculate dynamic pricing
        double totalCost = calculateDynamicPricing(vehicle, startDate, endDate);

        // Apply loyalty discounts
        totalCost = applyLoyaltyDiscount(customer, totalCost);

        // Check if the customer has sufficient balance
        if (customer.getBalance() < totalCost)
        {
            throw std::runtime_error("Insufficient balance to complete the rental.");
        }

        // Generate the rental contract
        RentalContract contract(customer, vehicle, startDate, endDate, totalCost);
        contracts.push_back(contract);

        // Mark the vehicle as rented
        garage.markVehicleAsRented(vehicle);

        // Deduct the cost from the customer's balance
        customer.deductBalance(totalCost);

        // Add loyalty points to the customer
        customer.addLoyaltyPoints(static_cast<int>(std::round(totalCost / 10)));

        std::cout << "Rental successful! Contract ID: " << contract.getContractId() << std::endl;

};

#endif // CARRENTALSYSTEM_H
