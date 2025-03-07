#include "../include/CarRentalSystem.h"
#include "../include/SUV.h"
#include "../include/Sedan.h"
#include "../include/Van.h"
#include "../include/Customer.h"

int main()
{
    CarRentalSystem system;

    // Add vehicles to the garage
    system.addVehicleToGarage(new SUV("Honda", "CRX", 2020, "ABC123"));
    system.addVehicleToGarage(new Sedan("Toyota", "Camry", 2019, "XYZ456"));
    system.addVehicleToGarage(new Van("Ford", "Transit", 2021, "DEF789"));

    // Create a customer
    Customer customer("Ethan", "Ethan.Ethan@example.com", "123-456-7890");

    // Rent a vehicle
    system.rentVehicle(customer, new SUV("Honda", "CRX", 2020, "ABC123"), "2023-10-01", "2023-10-07", 500.0);

    // Display all contracts
    system.displayAllContracts();

    return 0;
}